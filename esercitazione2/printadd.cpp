# include <iostream>

int main()
{
double ad[4] = {0.0, 1.1, 2.2, 3.3};
float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
int ai[3] = {0, 1, 2};

int x = 1;
float y = 1.1;

//Indirizzi Array
std::cout << "Indirizzi elementi di ad\n";
for(int i=0;i<4;i++)
{
    std::cout << &ad[i] << "\n";
}
std::cout << "Indirizzi elementi di af\n";
for(int i = 0; i<8; i++)
{
    std::cout << &af[i] << "\n";
}
std::cout << "Indirizzi elementi di ai\n";
for(int i = 0; i<3; i++)
{
    std::cout << &ai[i] << "\n";
}

std::cout <<"\nIndizzi x e y\n";
std::cout << &x << "\n";
std::cout << &y << "\n";
std::cout << "Calcolo a che indirizzo è salvato &y[1]:\n" << &(&y)[1]<<"(uguale all'indirizzo di x)\n"; //noto che è uguale all'indirizzo di x


(&y)[1] = 0;

std::cout << "\n" << x << "\n";

return 0;
}