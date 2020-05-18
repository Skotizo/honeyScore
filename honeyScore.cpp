#include <iostream>
#include <fstream>

using namespace std;
void getSize(string);

int main (int argc, const char *argv[])
{

  system("clear");
  system("");
  system("tput setaf 6; echo '███████╗██╗  ██╗ ██████╗ ████████╗██╗███████╗ ██████╗ '");
  system("echo '██╔════╝██║ ██╔╝██╔═══██╗╚══██╔══╝██║╚══███╔╝██╔═══██╗'");
  system("echo '███████╗█████╔╝ ██║   ██║   ██║   ██║  ███╔╝ ██║   ██║'");
  system("echo '╚════██║██╔═██╗ ██║   ██║   ██║   ██║ ███╔╝  ██║   ██║'");
  system("echo '███████║██║  ██╗╚██████╔╝   ██║   ██║███████╗╚██████╔╝'");
  system("echo '╚══════╝╚═╝  ╚═╝ ╚═════╝    ╚═╝   ╚═╝╚══════╝ ╚═════╝ '");

  system("tput sgr0; echo");
  system("echo 'Scan a list of IPs for honeypots\n'");
  cout << "USAGE : " << argv[0] << " ipList.txt > results.txt" << endl;

  system("echo '------------------------------------------------------'");
  string ip,raw;
  if(argv[1]==nullptr)
  {
    return 0;
  }
  string filename = argv[1];

  getSize(filename);

  ifstream infile;
  infile.open(filename,ios::in);

  while(infile)
  {

    infile >> ip;
    cout << "Result for " << ip <<endl;
    raw = "shodan honeyscore " + ip + " && echo";
    system(raw.c_str());


  }

  return 0;

}
void getSize(string filename)
{

	ifstream infile(filename, ios::binary);
  string buffer;
  int i = 0;

  while(infile)
  {

    infile >> buffer;
    i++;

  }

  buffer = "";
  cout << "File: " << filename << endl;
  cout << "Number of hosts: " << i << " IP addresses" << endl;
  system("echo '------------------------------------------------------\n'");
  if(i==0)
  {
    cout << "The file entered is nonexistant or empty" << endl << endl;
  }

  return;

}
