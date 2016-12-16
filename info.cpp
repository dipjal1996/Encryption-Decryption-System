#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
const int lim = 1e8 + 5;
#define inf 0x7fffffff

bool isComposite [N];
map < string , string > mtp;
inline void sieve()
{
    memset(isComposite, false, sizeof isComposite);
    for(int i = 2; i < N; ++i)
    {
        if(!isComposite[i])
        {
            for(int j = i + i ; j < N; j += i)
                isComposite[j] = true;
        }
    }
}


class EncryptionDecryption
{
public :
    string message;
    int length;

public :
    void init();
    void showmenu();
    bool control();
    void doEncryption() ;
    void doDecryption() ;
};

inline void EncryptionDecryption :: init()
{
    this -> message = "";
    length = 0;
}
inline void EncryptionDecryption :: showmenu()
{
    cout << "1. Do Encryption " << endl;
    cout << "2. Do Decryption " << endl;
    cout << "3. Exit" << endl;
    cout << "\n\nEnter Your Choice : " << endl;
}
inline bool EncryptionDecryption :: control()
{
    int x;
    cin >> x;
    if(x == 1)
    {
        this -> doEncryption();
        return true;
    }
    else if(x == 2)
    {
        this -> doDecryption();
        return true;
    }
    else if(x != 3)
    {
        cout << "Invalid Option!" << endl;
        return true;
    }
    else
    {
        cout << "Successfully Halted!" << endl;
        return false;
    }
}

string Substitution(string inp)
{
    int shift = 5;
    string res = "";
    for(int i = 0; i < (int) inp.size(); ++i)
    {
        if(inp[i] >= '0' && inp[i] <= '9')
        {
            char Next = (char) ((((inp[i] - '0') + shift) % 10) + '0');
            res += Next;
        }
        else
        {
            if(inp[i] >= 'a' && inp[i] <= 'z')
            {
                char Next = (char) ((((inp[i] - 'a') + shift) % 26) + 'a');
                res += Next;
            }
            else
            {
                if(inp[i] >= 'A' && inp[i] <= 'Z')
                {
                    char Next = (char) ((((inp[i] - 'A') + shift) % 26) + 'A');
                    res += Next;
                }
            }
        }
    }
    return res;
}

string Railfence(string inp)
{
  int i,j,counter,limit,index=0,len;
        char *cipherText;
        len=(int) inp.size();
        int n = 3;
        cipherText=(char*)malloc(sizeof(char)*(len+1));
        for(i=0; i<n; i++)
        {
            counter=0;
            for(j=i; j<len; j+=limit)
            {
                cipherText[index++]=inp[j];
                if(i==0 || i==n-1)
                    limit=2*n-2;
                else if(counter%2==0)
                    limit=2*(n-i-1);
                else
                    limit=2*i;
                if(limit<=0)
                    break;
                counter++;
            }
        }
        cipherText[index]='\0';
        string tmp = "";
        for(int i = 0; i < (int) strlen(cipherText); ++i)
            tmp += cipherText[i];
        return tmp;
}
inline void EncryptionDecryption :: doEncryption()
{
    cout << "Message to be encrypted : " << endl;
    cin >> this -> message;
    string s = this -> message;
    string Prime1 = "" , Prime2 = "" , Composite1 = "" , Composite2 = "" , Digit = "";
    bool pr = false , cmp = false;
    for(int i = 0; i < (int) s.size(); ++i)
    {
        if(i + 1 == 1)
        {
            continue;
        }
        if(s[i] >= '0' && s[i] <= '9')
        {
            Digit += s[i];
            continue;
        }
        if(!isComposite[i + 1])
        {
            if(!pr)
            {
                Prime1 += s[i];
            }
            else Prime2 += s[i];
            pr ^= true;
        }
        else
        {
            if(!cmp)
            {
                Composite1 += s[i];
            }
            else Composite2 += s[i];
            cmp ^= true;
        }
    }
    string res1 = Substitution(Prime1);
    string res5 = Substitution(Digit);
    string res2 = Substitution(Prime2);
    string res3 = Railfence(Composite1);
    string res4 = Railfence(Composite2);
    string answer = "";
    pr = false , cmp = false;
    int idx1 = 0 , idx2 = 0 , idx3 = 0 , idx4 = 0 , idx5 = 0;
    for(int i = 0; i < (int) s.size(); ++i)
    {
        if(i + 1 == 1)
        {
            answer += s[i];
            continue;
        }
        if(s[i] >= '0' && s[i] <= '9')
        {
            answer += res5[idx5++];
            continue;
        }
        if(!isComposite[i + 1])
        {
            if(!pr)
            {
                answer += res1[idx1++];
            }
            else answer += res2[idx2++];
            pr ^= true;
        }
        else
        {
            if(!cmp)
            {
                answer += res3[idx3++];
            }
            else answer += res4[idx4++];
            cmp ^= true;
        }
    }
    mtp[answer] = s;
    cout << "Encrypted Message : " << answer << endl;
}
inline void EncryptionDecryption :: doDecryption()
{
    cout << "Message to be Decrypted : " << endl;
    cin >> this -> message;
    string s = this -> message;
    string Prime1 = "" , Prime2 = "" , Composite1 = "" , Composite2 = "" , Digit = "";
    bool pr = false , cmp = false;
    for(int i = 0; i < (int) s.size(); ++i)
    {
        if(i + 1 == 1)
        {
            continue;
        }
        if(s[i] >= '0' && s[i] <= '9')
        {
            Digit += s[i];
            continue;
        }
        if(!isComposite[i + 1])
        {
            if(!pr)
            {
                Prime1 += s[i];
            }
            else Prime2 += s[i];
            pr ^= true;
        }
        else
        {
            if(!cmp)
            {
                Composite1 += s[i];
            }
            else Composite2 += s[i];
            cmp ^= true;
        }
    }
    bool mz = 0;
    string res1 = Substitution(Prime1);
    string res5 = Substitution(Digit);
    string res2 = Substitution(Prime2);
    string res3 = Railfence(Composite1);
    string res4 = Railfence(Composite2);
    string answer;
    if(mtp.find(s) == mtp.end()) {
        answer = "";
        mz = 1;
    } else answer = mtp[s];
    pr = false , cmp = false;
    int idx1 = 0 , idx2 = 0 , idx3 = 0 , idx4 = 0 , idx5 = 0;
    for(int i = 0; i < (int) s.size() && mz; ++i)
    {
        if(i + 1 == 1)
        {
            answer += s[i];
            continue;
        }
        if(s[i] >= '0' && s[i] <= '9')
        {
            answer += Digit[idx5++];
            continue;
        }
        if(!isComposite[i + 1])
        {
            if(!pr)
            {
                answer += res1[idx1++];
            }
            else answer += res2[idx2++];
            pr ^= true;
        }
        else
        {
            if(!cmp)
            {
                answer += res3[idx3++];
            }
            else answer += res4[idx4++];
            cmp ^= true;
        }
    }
    cout << "Decrypted Message : " << answer << endl;
}



EncryptionDecryption Edobject;
int main()
{
    sieve();
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    do
    {
        Edobject.init();
        Edobject.showmenu();
    }
    while(Edobject.control());
    return 0;}
