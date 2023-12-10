#include <iostream>
using namespace std;

int main()
{
    system("chcp 1251");
    setlocale(0, "RU");
    int choose = 0,idz = 0, idzChoose=-1;

    cout << "Доброго времени суток! :)" << endl;

    cout << "\nХотите ли вы иметь возможность инвертировать все биты на протяжении всей программы? \n 1. Да\n 2. Нет\n" << endl;
    cout << "Ваш выбор: ";
    cin >> idz;
    cout << "\n";

    while (choose != -1)
    {


        cout << "\n\n\nВыберите, что вы хотите сделать, и введите цифру, соответсвующую вашему желанию, из меню ниже: \n" \
            "1.Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без.\n" \
            "2. Вывести на экран двоичное представление в памяти (все разряды) целого числа, которое вы выберете сами.\n" \
            "3.Вывести на экран двоичное представление в памяти (все разряды) вещественного (от 3,4е-38 до 3,4е+38) числа, которое вы выберете сами.\n" \
            "4. Вывести на экран двоичное представление в памяти (все разряды) вещественного числа с повышенной точностью\n" \
            "(от 3, 4е - 38 до 3, 4е + 38) числа, которое вы выберете сами.\n" \
            "0. Завершить работу программы. \n\n\n";

        cout << "Ваш выбор: ";
        cin >> choose;
        cout << "\n";

        if (choose != 1 and choose != 2 and choose != 3 and choose != 4 and choose != 0)
            cout << "Такого пункта в меню нет :(\n";

        else
            switch (choose) {

                case 0: {
                    cout << "Пока-пока! :(\n\n";
                    choose = -1;
                }
                  break;

                case 1: {
                    cout << "Тип данных int занимает " << sizeof(int) << " байт(а).\n" \
                        "Тип данных short int занимает " << sizeof(short int) << " байт(а).\n" \
                        "Тип данных long int занимает " << sizeof(long int) << " байт(а).\n" \
                        "Тип данных float занимает " << sizeof(float) << " байт(а).\n" \
                        "Тип данных double занимает " << sizeof(double) << " байт(а).\n" \
                        "Тип данных long double занимает " << sizeof(long double) << " байт(а).\n" \
                        "Тип данных char занимает " << sizeof(char) << " байт(а).\n" \
                        "Тип данных bool занимает " << sizeof(bool) << " байт(а).\n";
                    // int, short int, long int, float, double, long double, char и bool
                }
                  break;

                case 2: {
                    int num, order;
                    unsigned int mask;

                    cout << "Введите целое число: ";
                    cin >> num;
                    cout << "\n";

                    order = sizeof(num) * 8 - 1;
                    mask = 1 << order;

                    for (int i = 0; i <= order; i++) {
                        cout << ((mask & num) ? 1 : 0);
                        mask >>= 1;

                        if (!i)
                            cout << " ";
                    }

                    if (idz == 1) {
                        num = ~num;    
                        cout << "\n\nИнвертировать все биты числа?\n 1. Да\n 2. Нет\n\n";
                        cout << "Ваш выбор: ";
                        cin >> idzChoose;
                        cout << "\n";
                    
                        if (idzChoose == 1) {
                        
                            mask = 1 << order;

                            for (int i = 0; i <= order; i++) {
                                cout << ((mask & num) ? 1 : 0);
                                mask >>= 1;

                                if (!i)
                                    cout << " ";
                            }

                        }

                        while (idzChoose == 1) {
                        
                            cout << "\n\nИнвертировать все биты числа ещё раз?\n 1. Да\n 2. Нет\n\n";
                            cout << "Ваш выбор: ";
                            cin >> idzChoose;
                            cout << "\n";

                            if (idzChoose == 1) {

                                num = ~num;
                                mask = 1 << order;

                                for (int i = 0; i <= order; i++) {
                                    cout << ((mask & num) ? 1 : 0);
                                    mask >>= 1;

                                    if (!i)
                                        cout << " ";
                                }

                            }
                        }
                    
                    }

                }
                  break;

                case 3: {
                    float numF;
                    int orderF;
                    unsigned int maskF;

                    cout << "Введите вещественное число: ";
                    cin >> numF;
                    cout << "\n";

                    orderF = sizeof(numF) * 8 - 1;
                    maskF = 1 << orderF;

                    union {
                        int intMemory;
                        float floatMemory;
                    };

                    floatMemory = numF;

                    for (int i = 0; i <= orderF; i++) {
                        cout << ((maskF & intMemory) ? 1 : 0);
                        maskF >>= 1;

                        if (!i or i == 8)
                            cout << " ";
                    }

                    if (idz == 1) {
                    
                        cout << "\n\nИнвертировать все биты числа?\n 1. Да\n 2.Нет\n\n";
                        cout << "Ваш выбор: ";
                        cin >> idzChoose;
                        cout << "\n";

                        if (idzChoose == 1) {

                            intMemory = ~intMemory;
                            maskF = 1 << orderF;

                            for (int i = 0; i <= orderF; i++) {
                                cout << ((maskF & intMemory) ? 1 : 0);
                                maskF >>= 1;

                                if (!i or i == 8)
                                    cout << " ";
                            }

                        }

                        while (idzChoose == 1) {

                            cout << "\n\nИнвертировать все биты числа ещё раз?\n 1. Да\n 2. Нет\n\n";
                            cout << "Ваш выбор: ";
                            cin >> idzChoose;
                            cout << "\n";

                            if (idzChoose == 1) {

                                intMemory = ~intMemory;
                                maskF = 1 << orderF;

                                for (int i = 0; i <= orderF; i++) {
                                    cout << ((maskF & intMemory) ? 1 : 0);
                                    maskF >>= 1;

                                    if (!i or i == 8)
                                        cout << " ";
                                }

                            }
                        }

                    }
                }
                  break;

                case 4: {
                    double numD;
                    int orderD;
                    unsigned int maskD;

                    cout << "Введите вещественное число с повышенной точностью: ";
                    cin >> numD;
                    cout << "\n";

                    orderD = sizeof(numD) * 8 - 1;
                    maskD = 1 << orderD;

                    union {
                        int intMemory[2];
                        double doubleMemory;
                    };

                    doubleMemory = numD;

                    for (int i = 0; i <= (orderD / 2); i++) {
                        cout << ((maskD & intMemory[1]) ? 1 : 0);
                        maskD >>= 1;

                        if (!i or i == 11)
                            cout << " ";
                    }

                    maskD = 1 << orderD;

                    for (int i = 0; i <= (orderD / 2); i++) {
                        cout << ((maskD & intMemory[0]) ? 1 : 0);
                        maskD >>= 1;
                    }

                    if (idz == 1) {

                        cout << "\n\nИнвертировать все биты числа?\n 1. Да\n 2.Нет\n\n";
                        cout << "Ваш выбор: ";
                        cin >> idzChoose;
                        cout << "\n";

                        if (idzChoose == 1) {

                            intMemory[0] = ~intMemory[0];
                            intMemory[1] = ~intMemory[1];
                            maskD = 1 << orderD;

                            for (int i = 0; i <= (orderD / 2); i++) {
                                cout << ((maskD & intMemory[1]) ? 1 : 0);
                                maskD >>= 1;

                                if (!i or i == 11)
                                    cout << " ";
                            }

                            maskD = 1 << orderD;

                            for (int i = 0; i <= (orderD / 2); i++) {
                                cout << ((maskD & intMemory[0]) ? 1 : 0);
                                maskD >>= 1;
                            }


                        }

                        while (idzChoose == 1) {

                            cout << "\n\nИнвертировать все биты числа ещё раз?\n 1. Да\n 2. Нет\n\n";
                            cout << "Ваш выбор: ";
                            cin >> idzChoose;
                            cout << "\n";

                            if (idzChoose == 1) {

                                intMemory[0] = ~intMemory[0];
                                intMemory[1] = ~intMemory[1];
                                maskD = 1 << orderD;

                                for (int i = 0; i <= (orderD / 2); i++) {
                                    cout << ((maskD & intMemory[1]) ? 1 : 0);
                                    maskD >>= 1;

                                    if (!i or i == 11)
                                        cout << " ";
                                }

                                maskD = 1 << orderD;

                                for (int i = 0; i <= (orderD / 2); i++) {
                                    cout << ((maskD & intMemory[0]) ? 1 : 0);
                                    maskD >>= 1;
                                }


                            }
                        }

                    }
                }
                  break;
            }
    }


    return 0;
}