#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

class CpLineToFile{
public:
    CpLineToFile() = default;
    bool openInputFile(const std::string& infilename, std::ios_base::openmode mode = std::ios_base::in)
    {
        infile.open(infilename, mode);
        return infile.is_open();
    }
    
    void process(const std::string& templateWord)
    {
        while( !(infile.eof()) )
        {
            std::getline(infile, line);
            line.push_back('\n');
            
            std::regex word_regex(templateWord, std::regex_constants::ECMAScript | std::regex_constants::icase);
            if(std::regex_search(line, word_regex))
            {            
                std::cout << line;
                outfile.write(line.c_str(), line.size());
            }
            /*
            if(line.find(templateWord) != std::string::npos)
            {            
                std::cout << line;
                outfile.write(line.c_str(), line.size());
            }
            */
        }
        
        infile.close();
        outfile.close();
    }
    
    bool openOutPutFile(const std::string& outfilename, std::ios_base::openmode mode = std::ios_base::out)
    {
        outfile.open(outfilename, mode);
        return outfile.is_open();
    }

private:
    std::string     line;
    std::ifstream   infile;
    std::ofstream   outfile;
};

int main(int argc, char* argv[])
{
    if(argc < 4)
    {
        std::cout << "docstring: This is a small program used to copy lines with \n\
        specific word to another file. Also the word to be\n\
        specified is non case sensitive.\n";
        std::cout << "usage: "
            << "program_name infilename  templateWord  outfilename\n";
        exit(1);
    }
    
    std::string infilename = argv[1];
    std::string templateWord = argv[2];
    std::string outfilename = argv[3];
    
    CpLineToFile obj;
    if(obj.openInputFile(infilename))
        std::cout << "open input file \"" << infilename << "\" OK.\n";
    else
        std::cout << "open input file \"" << infilename << "\" false.\n";
    
    if(obj.openOutPutFile(outfilename))
        std::cout << "open output file \"" << outfilename << "\" OK.\n";
    else
        std::cout << "open output file \"" << outfilename << "\" false.\n";
    
    obj.process(templateWord);
    
    
    
    return 0;
}