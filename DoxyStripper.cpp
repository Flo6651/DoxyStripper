#include <string>
#include <iterator>
#include <iostream>
#include <fstream>
using namespace std;

int split(int argc,char* argv[])
{

    cout<<"split";
 std::string content{ std::istreambuf_iterator<char>(cin),std::istreambuf_iterator<char>() };
//    string content="Tes Strinf Gasdgsa";
    const string begin="\\begin{document}";
    const string end="\\end{document}";
    size_t middle = content.find(begin);
    size_t send=content.find(end);
    fstream header;
    string hederfile=argv[2];
    hederfile+=".head.tex";
    header.open(hederfile, std::fstream::out);
    copy(content.cbegin(),content.cbegin()+middle,ostream_iterator<string::const_iterator::value_type>(header));
    header.close();

    fstream body;
    string bodyfile=argv[2];
    bodyfile+=".body.tex";
    body.open(bodyfile, std::fstream::out);
    copy(content.cbegin()+middle+begin.length(),content.cbegin()+send,ostream_iterator<string::const_iterator::value_type>(body));
    body.close();
    return 0;
}

int shortn(int argc , char* argv[])
{
    cout<<"shortn";
    std::string content{ std::istreambuf_iterator<char>(cin),std::istreambuf_iterator<char>() };
    const string begin="\\begin{titlepage}";
    const string end="\\end{titlepage}";
    const string del="\\printindex";
    size_t middle = content.find(begin);
    size_t send=content.find(end);
    size_t sdel=content.find(del);
    cout<<send<<" "<<content.length();
    fstream body;
    string bodyfile=argv[2];
    body.open(bodyfile, std::fstream::out);
    content.replace(sdel,del.length()," " );
    copy(content.cbegin(),content.cbegin()+middle,ostream_iterator<string::const_iterator::value_type>(body));
    copy(content.cbegin()+send+end.length(),content.cbegin()+content.length()-1,ostream_iterator<string::const_iterator::value_type>(body));
    
    body.close();
    return 0;
}


int main( int argc, char *argv[])
{

    cout <<argv[0]<<endl<<argv[1]<<endl<<argv[2]<<endl;
    if(argc!=3)
        return -1;
    
    string s =argv[1];
    cout<<s[0];
    switch (s[1])
    {
    case 's':
        return split(argc,argv);
        break;
    case 'l':
        return shortn(argc,argv);
    default:
        break;
    }
   
}