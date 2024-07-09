#include <bits/stdc++.h>

namespace Hreem
{
    char capital(int c)
    {
        if (c >= 97 && c <= 122)
        {
            c -= 32;
            char t = c;
            return t;
        }
        char t = c;
        return t;
    }
    char small(int c)
    {
        if (c > 65 && c < 97)
        {
            c += 32;
            char t = c;
            return t;
        }
        char t = c;
        return t;
    }
    std::string niggafiy(std::string msg)
    {
        std::string m = msg;
        int l = msg.length();
        int flag = 1;
        for (int i = 0; i <= l - 1; i++)
        {
            char c = m[i];
            if (flag == 0)
            {
                m[i] = capital(c);
                flag = 1;
            }
            else if (flag == 1)
            {
                m[i] = small(c);
                flag = 0;
            }
        }
        return m;
    }
    void print(std::string msg)
    {
        msg = niggafiy(msg);
        std::cout << "Hreem Nigga Says: " << msg << std::endl;
    }
}
namespace Gojo
{
    char capital(int c)
    {
        if (c >= 97 && c <= 122)
        {
            c -= 32;
            char t = c;
            return t;
        }
        char t = c;
        return t;
    }
    std::string chadify(std::string msg)
    {
        std::string m = msg;
        int l = msg.length();
        int flag = 1;
        for (int i = 0; i <= l - 1; i++)
        {
            char c = m[i];
            m[i] = capital(c);
        }
        return m;
    }
    void print(std::string msg)
    {
        msg = chadify(msg);
        std::cout << "Honoured One Says: " << msg << std::endl;
    }
}
int main()
{
    Hreem::print("Kaalo is so hot");
    Gojo::print("yes!");
    return 0;
}