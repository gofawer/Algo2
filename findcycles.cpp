//Cześć 

//Ola poprosiła o kilka rad dla Was odnośnie SW Testu. Więc zebraliśmy na szybko kilka pomysłów. Mamy nadzieję, że się przydadzą  Coś może być dla Was oczywiste, a coś innego przełomowe ;) Nie mieliśmy okazji się spotkać i pogadać, więc po prostu przekazujemy, co dla nas wydaje się istotne 

//1.	To nie jest rocket science, to ma po prostu działać.
//2.	Jeśli po usłyszeniu, że nie wolno używać STL pierwsza Twoja myśl to „muszę zaimplementować własny vector, queue, itd.”, to nie idź tą drogą, bo źle czynisz ;)
//3.	W zadaniu masz podane zakresy danych. Na ogół są one stosunkowo małe, więc algorytmy nie muszą być mega wydajne. Mają być „skrojone” na miarę wyłącznie tego jednego zadania. Można zastosować duże uproszczenia. Przykładowy problem do przemyślenia: jak w ciągu 5 minut zaimplementować kolejkę priorytetową wykorzystując globalną tablicę wiedząc, że w tej kolejce nigdy nie będzie więcej niż 150 elementów.
//4.	Ćwicząc, omawiajcie wspólnie swoje problemy, rozwiązania, hacki i pomysły 

//To były 3 punkty na rozgrzewkę. A teraz to, co najważniejsze:
//1.	Zróbcie zadania z poprzednich SW Testów.
//2.	Nauczcie się pisać w jak najkrótszym czasie algorytm DFS (Depth-first search, przeszukiwanie grafu wgłąb). Implementacja ma być jak najprostsza, rekurencyjna i wykorzystująca globalne tablice i zmienne.
//3.	Niech każdy znajdzie najwygodniejszy dla siebie sposób reprezentacji grafu za pomocą globalnych tablic. W zadaniu dostaje się jakieś zręby kodu, które można potem wykorzystać. ALE NIE TRZEBA  Jeśli zaproponowane kawałki kodu Ci się nie podobają, to się ich pozbądź i zrób po swojemu.

//Przykładowa reprezentacja grafu w „zrębach kodu” danych na SW Tescie:
//int A[1000], B[1000];
//int Answer[100], AnswerN;

//Dla mnie to było całkowicie nieczytelne, więc zrobiłem po swojemu:
//int V[101][1000];
//int vN[101]; //edges count for vertex

//V to tablica reprezentująca krawędzie wychodzące z każdego wierzchołka grafu. Z treści zadania wiedziałem, że wierzchołki są nazywane od 1 do 100. Stąd 101 elementów w pierwszym wymiarze tablicy. I wiedziałem, że w całym grafie będzie maksymalnie 1000 krawędzi. Czyli w szczególnym przypadku może być 1000 krawędzi przypisanych do jednego wierzchołka.
//W tablicy V przechowuję indeksy wierzchołków, do których prowadzą kolejne krawędzie.
//Tablica vN numer pierwszego niezajętego pola w tablicy V dla danego wierzchołka.

//Przechodzenie po sąsiadach wybranego wierzchołka currentVertexNum wygłąda tak:

//    for (int i = 0; i < vN[currentVertexNum]; ++i)
//    {
//        int neighborVertexNum = V[currentVertexNum][i];
//    }


//W załączniku umieszczam moje rozwiązanie zadania z SW Test, w którym trzeba było znaleźć jeden dowolny cykl w zadanym grafie i wypisać wierzchołki należące do tego cyklu w kolejności rosnącej. Jest to rozwiązanie podobne do tego, które napisałem na teście i zdałem 
//Zwróćcie uwagę, że nie jest to rozwiązanie ani bardzo optymalne, ani najpiękniejsze. Nie zawiera żadnych skomplikowanych struktur danych, nie ma nic wspólnego z programowaniem obiektowym i nie będzie uniwersalne. Nie będzie też łatwe w późniejszym utrzymaniu, ale... przecież to ma być jednorazowe rozwiązanie pod konkretny zestaw danych. Więc właśnie o to chodzi – ma być prosto, krótko i skrojone na miare 

//Pozdrawiam i powodzenia,





// =============================================
// Author: Mariusz Seklecki (m.seklecki@samsung.com)
// The sample solution for finding cycles in graph task
#include<iostream>

using namespace std;

int N, M;
int V[101][1000];
int vN[101]; //edges count for vertex
bool visited[101];
bool verticesCycle[101];
bool visitedInCurrent[101];
int cycleVertexNum;
bool addVerticesToCycle;

//returns 0 if no cycle
//returns vertexNum where cycle found
bool dfsFindCycle(int vertexNum)
{
    if (visitedInCurrent[vertexNum])
    {
        verticesCycle[vertexNum] = true;
        cycleVertexNum = vertexNum;
        addVerticesToCycle = true;
        return true;
    }

    visited[vertexNum] = true;
    visitedInCurrent[vertexNum] = true;

    for (int i = 0; i < vN[vertexNum]; ++i)
    {
        if (dfsFindCycle(V[vertexNum][i]))
        {
            if (vertexNum == cycleVertexNum)
            {
                addVerticesToCycle = false;
            }

            if (addVerticesToCycle)
            {
                verticesCycle[vertexNum] = true;
            }
            return true;
        }
    }

    visitedInCurrent[vertexNum] = false;

    return 0;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);

    int test_case;

    // freopen opens text file and pass it to stdin
    freopen("sample_input.txt", "r", stdin);

    for (test_case = 1; test_case <= 10; ++test_case)
    {
        int i;

        // reading input

        for (i = 0; i <= N; ++i)
        {
            vN[i] = 0;
            visited[i] = false;
            verticesCycle[i] = false;
            visitedInCurrent[i] = false;
        }
        cycleVertexNum = 0;
        addVerticesToCycle = false;

        cin >> N >> M;
        int x;
        int y;
        for (i = 0; i < M; i++)
        {
            cin >> x >> y;
            V[x][vN[x]++] = y;
        }

        // solution

        bool foundCycle = false;
        for (i = 1; i <= N; ++i)
        {
            if (!visited[i] && vN[x] > 0)
            {
                if (dfsFindCycle(i /*vertex num*/))
                {
                    foundCycle = true;
                    break;
                }

            }
        }


        // printing answer
        cout << "#" << test_case;
        if (!foundCycle)
        {
            cout << " 0" << endl;
        }
        else
        {
            for (i = 1; i <= N; ++i)
            {
                if (verticesCycle[i])
                {
                    cout << " " << i;
                }
            }
            cout << endl;
        }
    }

    return 0;
}

