#include <string>
#include <iterator>
#include <iostream>
#include <fstream>
using namespace std;


int main( int argc, char *argv[])
{
    if(argc!=2)
        return -1;
    std::string content{ std::istreambuf_iterator<char>(cin),std::istreambuf_iterator<char>() };
//    string content="Tes Strinf Gasdgsa";
    const string begin="\\begin{document}";
    const string end="\\end{document}";
    size_t middle = content.find(begin);
    size_t send=content.find(end);
    fstream header;
    string hederfile=argv[1];
    cout <<argv[0]<<endl<<argv[1];
    hederfile+=".head.tex";
    header.open(hederfile, std::fstream::out);
    copy(content.cbegin(),content.cbegin()+middle,ostream_iterator<string::const_iterator::value_type>(header));
    header.close();

    fstream body;
    string bodyfile=argv[1];
    cout <<argv[0]<<endl<<argv[1];
    bodyfile+=".body.tex";
    body.open(bodyfile, std::fstream::out);
    copy(content.cbegin()+middle+begin.length(),content.cbegin()+send,ostream_iterator<string::const_iterator::value_type>(body));
    body.close();
}