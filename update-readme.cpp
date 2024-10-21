#include <bits/stdc++.h>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;

class UpdateReadme {
    std::unordered_map<std::string, std::string> fileTypes;
    std::stringstream ss;
    fs::path base_path;
    enum struct Source { PROJ_EULER, LEETCODE, KATTIS, CODEFORCES };

    const std::string KATTIS_HEAD = "<table>\n\t<tr>\n\t\t<th colspan='2'>Kattis Questions</th>\n</tr>\n"
                "\t<tr>\n\t\t<td>Name</td><td>Solution File</td>\n";
    const std::string KATTIS_TAIL = "</table>";

    const std::string LEETCODE_HEAD = "<table>\n\t<tr>\n\t\t<th colspan='3'>Leetcode Questions</th>\n</tr>\n"
                "\t<tr>\n\t\t<td>Index</td><td>Name</td><td>Solution File</td>\n";
    const std::string LEETCODE_TAIL = "</table>";

    const std::string PROJ_EULER_HEAD = "<table>\n\t<tr>\n\t\t<th colspan='3'>Project Euler Questions</th>\n</tr>\n"
                "\t<tr>\n\t\t<td>Index</td><td>Solution File</td><td>Writeup</td>\n";
    const std::string PROJ_EULER_TAIL = "</table>";

public:
    UpdateReadme() {
        fileTypes = { {"py", "Python"}, {"cpp", "C++"} };
        base_path = fs::path(__FILE__).parent_path();
        for (auto& dir_entry : fs::directory_iterator(base_path)) {
            if (fs::is_directory(dir_entry)) {
                fs::path p = dir_entry.path();
                std::string p0 = p.filename();
                std::cout << p;
                if (p0[0] >= 65 && p0[0] <= 90) {
                    if (p0 == "Kattis") {
                        std::stringstream kattis_ss;
                        format(kattis_ss, Source::KATTIS, p);
                        ss << kattis_ss.str();
                    } else if (p0 == "Leetcode") {
                        std::stringstream leetcode_ss;
                        format(leetcode_ss, Source::LEETCODE, p);
                        ss << leetcode_ss.str();
                    } else if (p0 == "Project Euler") {
                        std::stringstream proj_euler_ss;
                        format(proj_euler_ss, Source::PROJ_EULER, p);
                        ss << proj_euler_ss.str();
                    } else if (p0 == "Codeforces") {
                        // Not implemented yet
                    }
                }
            }
        }
    }

    void write(std::string fileName) {
        std::ofstream output;
        output.open(fileName);
        output << ss.rdbuf();
        output.close();
    }

    void format(std::stringstream &ss, Source s, fs::path &p) {
        std::string qn, qn_link, sol_type, sol_link, opt;
        fs::path folder_path, sol_path;
        fs::directory_entry sol_file;
        auto fileCmpByAlphabet = [](fs::directory_entry f1, fs::directory_entry f2) {
            std::string s1 = std::string(f1.path().filename());
            std::string s2 = std::string(f2.path().filename());
            return (s1 < s2); 
        };
        auto fileCmpByIndex = [](fs::directory_entry f1, fs::directory_entry f2) {
            std::string s1 = std::string(f1.path().filename());
            std::string s2 = std::string(f2.path().filename());
            int i1 = s1.find('-'), i2 = s2.find('-');
            std::string t1 = s1.substr(0, i1), t2 = s2.substr(0, i2);
            return (t1.length() < t2.length() || stoi(t1) < stoi(t2)); 
        };

        std::set<fs::directory_entry, decltype(fileCmpByAlphabet)> v1(fileCmpByAlphabet);
        std::set<fs::directory_entry, decltype(fileCmpByIndex)> v2(fileCmpByIndex);
        v1.clear();
        v2.clear();

        switch(s) {
            case Source::KATTIS:
                ss << KATTIS_HEAD;
                for (auto& entry : fs::directory_iterator(p)) {
                    if (fs::is_directory(entry)) {
                        v1.emplace(entry);
                    }
                }
                for (auto it = v1.begin(); it != v1.end(); ++it) {
                    folder_path = (*it).path();
                    ss << formatEntry(s, qn, folder_path, qn_link, sol_file, sol_type, sol_path, sol_link, opt);
                }
                ss << KATTIS_TAIL;
            break;

            case Source::LEETCODE:
                ss << LEETCODE_HEAD;
                for (auto& entry : fs::directory_iterator(p)) {
                    if (fs::is_regular_file(entry)) {
                        v2.emplace(entry);
                    }
                }
                for (auto it = v2.begin(); it != v2.end(); ++it) {
                    sol_file = *it;
                    ss << formatEntry(s, qn, folder_path, qn_link, sol_file, sol_type, sol_path, sol_link, opt);
                }
                ss << LEETCODE_TAIL;
            break;

            case Source::PROJ_EULER:
                ss << PROJ_EULER_HEAD;
                for (auto& entry : fs::directory_iterator(p)) {
                    if (fs::is_directory(entry)) {
                        v1.emplace(entry);
                    }
                }
                for (auto it = v1.begin(); it != v1.end(); ++it) {
                    folder_path = (*it).path();
                    ss << formatEntry(s, qn, folder_path, qn_link, sol_file, sol_type, sol_path, sol_link, opt);
                }
                ss << PROJ_EULER_TAIL;
            break;
        }
    }

    void fileType(std::string &file_name, std::string &file_type) {
        int i = file_name.find(".");
        file_type = fileTypes[file_name.substr(i+1)];
        file_name = file_name.substr(0, i);
    }

    std::string formatEntry(Source s, std::string &qn, fs::path &folder_path, std::string &qn_link,
        fs::directory_entry &sol_file, std::string &sol_type, fs::path &sol_path, std::string &sol_link,
        std::string &opt) {

        switch(s) {
            case Source::KATTIS: {
                qn = folder_path.filename();
                sol_file = *(fs::begin(fs::directory_iterator(folder_path)));                
                sol_path = fs::relative(sol_file.path(), base_path);
                opt = sol_path.filename();
                fileType(opt, sol_type);
                qn_link = "https://open.kattis.com/problems/" + qn;

                return "\t<tr>\n\t\t<td>" + formatLink(qn, qn_link) + "</td>"
                        "<td>" + formatLink(sol_type, sol_path.string()) + "</td></tr>\n";
            } break;
            case Source::LEETCODE: {
                sol_path = sol_file.path();
                qn = sol_path.filename();
                fileType(qn, sol_type);
                int t0 = qn.find("-");
                opt = qn.substr(0, t0);
                qn = qn.substr(t0+1);
                qn_link = "https://leetcode.com/problems/" + qn;
                sol_path = fs::relative(sol_path, base_path);

                return "\t<tr>\n\t\t<td>" + opt + "</td>"
                        "<td>" + formatLink(qn, qn_link) + "</td>"
                        "<td>" + formatLink(sol_type, sol_path) + "</td></tr>\n";
            } break;
            case Source::PROJ_EULER: {
                qn = folder_path.filename();
                qn_link = "https://projecteuler.net/problem=" + qn;
                opt = "";
                for (auto& file : fs::directory_iterator(folder_path)) {
                    if (fs::is_regular_file(file)) {
                        std::string s1 = file.path().filename(), s2;
                        fileType(s1, s2);
                        if (s1 == "solution") {
                            sol_type = s2;
                            sol_path = fs::relative(file.path(), base_path);
                        } else if (s1 == "writeup") {
                            opt = fs::relative(file.path(), base_path);
                        }
                    }
                }
                return "\t<tr>\n\t\t<td>" + formatLink(qn, qn_link) + "</td>"
                        "<td>" + formatLink(sol_type, sol_path) + "</td>" 
                        "<td>" + (opt != "" ? formatLink("Writeup", opt) : "No writeup found") + "</td></tr>\n";
            } break;
        }
        return "";
    }

    std::string formatLink(std::string name, std::string path) {
        return ("<a href=\"" + path + "\">" + name + "</a>");
    }

};

int main() {
    UpdateReadme u;
    u.write("README.md");
}