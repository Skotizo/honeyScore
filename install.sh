sudo apt install g++ python python3 python-setuptools python3-setuptools python-pip python3-pip
pip install shodan
g++ honeyScore.cpp -o honeyScore
clear
echo "Shodan has been installed."
echo -n "Paste your Shodan API key: "
read key
shodan init $key
echo
./honeyScore
