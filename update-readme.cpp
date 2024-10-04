#include <bits/stdc++.h>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;

class UpdateReadme {
    std::unordered_map<std::string, std::string> fileTypes;
    std::stringstream ss;
    fs::path base_path;
public:
    UpdateReadme() {
        fileTypes = { {"py", "Python"}, {"cpp", "C++"} };
        base_path = fs::path(__FILE__).parent_path();
        for (auto& dir_entry : fs::directory_iterator(base_path)) {
            if (fs::is_directory(dir_entry)) {
                std::string p = dir_entry.path().filename();
                std::cout << p;
                if (p[0] >= 65 && p[0] <= 90) {
                    if (p == "Kattis") {
                        std::stringstream kattis_ss;
                        kattis_ss << "<table>\n\t<tr>\n\t\t<th colspan='2'>Kattis Questions</th>\n</tr>\n"
                                << "\t<tr>\n\t\t<td>Name</td><td>Solution File</td>\n";
                        for (auto& entry : fs::directory_iterator(p)) {
                            if (fs::is_directory(entry)) {
                                std::string qn = entry.path().string();
                                fs::directory_entry sol_file = *(fs::begin(fs::directory_iterator(qn)));
                                std::vector<std::string> f_info = formatKattis(entry.path().filename().string(), sol_file.path());
                                kattis_ss << "\t<tr>\n\t\t<td>" << formatLink(f_info[0], f_info[1]) << "</td>"
                                        << "<td>" << formatLink(f_info[3], f_info[2]) << "</td></tr>\n";
                            }
                        }
                        kattis_ss << "</table>";
                        ss << kattis_ss.str();
                    } else if (p == "Leetcode") {
                        std::stringstream leetcode_ss;
                        leetcode_ss << "<table>\n\t<tr>\n\t\t<th colspan='3'>Leetcode Questions</th>\n</tr>\n"
                                << "\t<tr>\n\t\t<td>Index</td><td>Name</td><td>Solution File</td>\n";
                        for (auto& entry : fs::directory_iterator(p)) {
                            if (fs::is_regular_file(entry)) {
                                std::string qn = entry.path().filename();
                                std::pair<std::string, std::string> ft = fileType(qn);
                                std::vector<std::string> fname = formatLeetcode(ft.first);
                                leetcode_ss << "\t<tr>\n\t\t<td>" << fname[0] << "</td>"
                                        << "<td>" << formatLink(fname[1], fname[2]) << "</td>"
                                        << "<td>" << formatLink(ft.second, fs::relative(entry.path(), base_path)) 
                                        << "</td></tr>\n";
                            }
                        }
                        leetcode_ss << "</table>";
                        ss << leetcode_ss.str();
                    } else if (p == "Project Euler") {
                        std::stringstream proj_euler_ss;
                        proj_euler_ss << "<table>\n\t<tr>\n\t\t<th colspan='3'>Project Euler Questions</th>\n</tr>\n"
                                << "\t<tr>\n\t\t<td>Index</td><td>Solution File</td><td>Writeup</td>\n";
                        for (auto& entry : fs::directory_iterator(p)) {
                            if (fs::is_directory(entry)) {
                                std::string qn = entry.path().filename();
                                std::vector<std::string> f_info = formatProjEuler(entry.path().string(), qn);
                                proj_euler_ss << "\t<tr>\n\t\t<td>" << formatLink(qn, f_info[0]) << "</td>"
                                        << "<td>" << formatLink(f_info[1], f_info[2]) << "</td>" 
                                        << "<td>" << (f_info[3] != "" ? formatLink("Writeup", f_info[3]) : "No writeup found") << "</td></tr>\n";
                            }
                        }
                        proj_euler_ss << "</table>";
                        ss << proj_euler_ss.str();
                    } else if (p == "Codeforces") {
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

    std::pair<std::string, std::string> fileType(std::string file) {
        int i = file.find(".");
        std::string fileName = file.substr(0, i);
        std::string fileType = file.substr(i+1);
        return std::pair(fileName, fileTypes[fileType]);
    }

    std::vector<std::string> formatLeetcode(std::string file) {
        int i = file.find("-");
        std::string k = file.substr(0, i);
        std::string qnName = file.substr(i+1);
        std::string qnLink = "https://leetcode.com/problems/" + qnName;
        return std::vector({k, qnName, qnLink});
    }

    std::vector<std::string> formatProjEuler(std::string qnPath, std::string qn) {
        std::vector<std::string> res(4, "");
        res[0] = "https://projecteuler.net/problem=" + qn;
        for (auto& file : fs::directory_iterator(qnPath)) {
            if (fs::is_regular_file(file)) {
                std::pair<std::string, std::string> ft = fileType(file.path().filename());
                if (ft.first == "solution") {
                    res[1] = ft.second;
                    res[2] = fs::relative(file.path(), base_path);
                } else if (ft.first == "writeup") {
                    res[3] = fs::relative(file.path(), base_path);
                }
            }
        }
        return res;
    }

    std::vector<std::string> formatKattis(std::string qn, fs::path sol_file) {
        std::string solFileLink = fs::relative(sol_file, base_path);
        std::string solFileType = (fileType(sol_file.filename())).second;
        std::string qnLink = "https://open.kattis.com/problems/" + qn;
        return std::vector({qn, qnLink, solFileLink, solFileType});
    }

    std::string formatLink(std::string name, std::string path) {
        return ("<a href=\"" + path + "\">" + name + "</a>");
    }

};

int main() {
    UpdateReadme u;
    u.write("README.md");
}