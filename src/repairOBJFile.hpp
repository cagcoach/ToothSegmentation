/* Author: Christian Grund
 *
 * This Replaces the commas in the .obj files by points and saves into a new file.
*/




#ifndef REPAIROBJFILE_H
#define REPAIROBJFILE_H

#include <string>
#include <iostream>
#include <fstream>


class RepairOBJFile{
public:
    static void repair(std::string in_, std::string out_){
    std::ifstream in(in_);
    std::ofstream out(out_);

    if (!in)
    {
        std::cerr << "Could not open " << in_ << "\n";
        throw "Could not open input file";
    }

    if (!out)
    {
        std::cerr << "Could not open " << out_ << "\n";
        throw "Could not open output file";
    }
    out << "# FIXED FILE: ',' has been replaced with '.'\n";
    std::string line;
    while (getline(in, line))
    {
        while (true)
        {
            size_t pos = line.find(",");
            if (pos != std::string::npos)
                line.replace(pos, 1, ".");
            else
                break;
        }

        out << line << '\n';
    }
   }

};

#endif
