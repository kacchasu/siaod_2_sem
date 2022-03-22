#include "infauto.h"
istream& operator >> (istream& in, Date& date)
{
    cout << endl;
    cout << "Enter day: ";
    cin >> date.day;
    cout << "Enter month: ";
    cin >> date.month;
    cout << "Enter year: ";
    cin >> date.year;
    return in;
}
istream& operator >> (istream& in, InfAuto& ia)
{
    cout << "Enter number: ";
    in >> ia.number;
    cout << "Enter model: ";
    in >> ia.model;
    cout << "Enter color: ";
    in >> ia.color;
    cout << "Enter owner: ";
    in >> ia.owner;
    cout << "Enter last inspection date: ";
    in >> ia.date;
    return in;
}
ostream& operator << (ostream& out, const Date& date)
{
    cout << date.day << "." << date.month << "." << date.year;
    return out;
}
ostream& operator << (ostream& out, const InfAuto& ia)
{
    out << "Number: " << ia.number << endl;
    out << "Model: " << ia.model << endl;
    out << "Color: " << ia.color << endl;
    out << "Owner: " << ia.owner << endl;
    out << "Last inspection date: " << ia.date << endl;
    return out;
}
ostream& operator << (ostream& out, const SheetAuto& sheet)
{
    for (int i = 0; i < sheet.autosheet.size(); i++) {
        out << i + 1 << " car" << endl << "===================" << endl;
        out << sheet.autosheet[i];
        out << "===================" << endl;
    }
    return out;
}

bool comp(InfAuto arg1, InfAuto arg2)
{
    if (arg1.date.year > arg2.date.year)
        return true;
    else if (arg1.date.year > arg2.date.year)
        return false;
    else if (arg1.date.month > arg2.date.month)
        return true;
    else if (arg1.date.month < arg2.date.month)
        return false;
    else if (arg1.date.day > arg2.date.day)
        return true;
    else
        return false;
}

void sort(SheetAuto& sheet)
{
    InfAuto tmp;
    for (int i = sheet.autosheet.size() - 1; i >= 0; i--)
        for (int j = 0; j < i; j++)
            if (comp(sheet.autosheet[j], sheet.autosheet[j + 1]))
            {
                tmp = sheet.autosheet[j];
                sheet.autosheet[j] = sheet.autosheet[j + 1];
                sheet.autosheet[j + 1] = tmp;
            }
}

void insert(SheetAuto& sheet, InfAuto ia)
{
    sheet.autosheet.push_back(ia);
    sort(sheet);
}

void delete_auto(SheetAuto& sheet, string rnumber)
{
    for (int i = 0; i < sheet.autosheet.size(); i++)
        if (sheet.autosheet[i].number == rnumber)
        {
            sheet.autosheet.erase(sheet.autosheet.begin() + i);
            break;
        }
}

SheetAuto color_model(SheetAuto& sheet, string rmodel, string rcolor)
{
    SheetAuto newsheet;
    for (int i = 0; i < sheet.autosheet.size(); i++)
        if (sheet.autosheet[i].model == rmodel && sheet.autosheet[i].color == rcolor)
            insert(newsheet, sheet.autosheet[i]);
    return newsheet;
}

int main()
{
    cout << "Enter amount of cars: ";
    int endn;
    cin >> endn;
    int amount = 0;
    SheetAuto sheetauto;
    for (int i = 0; i < endn; i++)
    {
        InfAuto tmp;
        amount++;
        cout << "Enter " << amount << " car" << endl;
        cin >> tmp;
        sheetauto.autosheet.push_back(tmp);
    }
    cout << sheetauto;
    cout << "Enter number for delete: ";
    string rnumber;
    cin >> rnumber;
    delete_auto(sheetauto, rnumber);
    cout << "Enter car for insert" << endl;
    InfAuto rcar;
    cin >> rcar;
    insert(sheetauto, rcar);
    cout << sheetauto;
    cout << "Enter color for list: ";
    cin >> rnumber;
    cout << "Enter model for list: ";
    string rmodel;
    cin >> rmodel;
    cout << color_model(sheetauto, rmodel, rnumber);
}
