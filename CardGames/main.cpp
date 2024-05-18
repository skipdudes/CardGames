#include <iostream>
#include <ctime>
using namespace std;

// Wyœwietlane wartoœci kart
#define TWO_NAME "2"
#define THREE_NAME "3"
#define FOUR_NAME "4"
#define FIVE_NAME "5"
#define SIX_NAME "6"
#define SEVEN_NAME "7"
#define EIGHT_NAME "8"
#define NINE_NAME "9"
#define TEN_NAME "10"
#define JACK_NAME "J"
#define QUEEN_NAME "Q"
#define KING_NAME "K"
#define ACE_NAME "A"

// Wyœwietlane kolory kart
#define SPADE_NAME "Pik"
#define HEART_NAME "Kier"
#define CLUB_NAME "Trefl"
#define DIAMOND_NAME "Karo"

// Je¿eli w danym miejscu nie ma karty, wyœwietlony zostanie poni¿szy napis
#define EMPTY_CARD_NAME "Wolne miejsce"

// Struktura definiuj¹ca pojedyncz¹ kartê
struct card
{
    // Wartoœæ karty (np. As, Dama, Dwójka)
    enum
    {
        TWO, THREE, FOUR,
        FIVE, SIX, SEVEN,
        EIGHT, NINE, TEN,
        JACK, QUEEN, KING, ACE,
        EMPTY_VALUE
    } value;

    // Kolor karty (np. Trefl, Karo)
    enum
    {
        SPADE,
        HEART,
        CLUB,
        DIAMOND,
        EMPTY_SUIT
    } suit;
};

// Funkcja zwracaj¹ca true lub false, w zale¿noœci czy karta jest pusta
bool isCardEmpty(card card)
{
    if (card.value != card::EMPTY_VALUE && card.suit != card::EMPTY_SUIT)
        return false;

    return true;
}

// Funkcja sprawdza czy rêka gracza zawiera chocia¿ jedn¹ pust¹ kartê
bool isHandEmpty(card* hand, int deckSize)
{
    for (int i = 0; i < deckSize; i++)
    {
        if (!isCardEmpty(hand[i]))
            return false;
    }

    return true;
}

// Funkcja ustawia wartoœci karty tak, aby by³a pust¹ kart¹
void setCardEmpty(card* card)
{
    card->value = card::EMPTY_VALUE;
    card->suit = card::EMPTY_SUIT;
}

// Funkcja tworzy podstawow¹ taliê kart, w zale¿noœci od liczby kart przypadaj¹cej na kolor
void createDeck(card* cards, int deckSize, int numberOfCardsPerSuit)
{
    // Pomocnicza zmienna u¿ywana przy przydzielaniu wartoœci karty
    int deckCheck = 52 - deckSize;

    for (int i = 0; i < deckSize; i++)
    {
        // Ustalanie wartoœci karty
        switch ((i % numberOfCardsPerSuit) + (deckCheck / 4))
        {
        case 0: cards[i].value = card::TWO; break;
        case 1: cards[i].value = card::THREE; break;
        case 2: cards[i].value = card::FOUR; break;
        case 3: cards[i].value = card::FIVE; break;
        case 4: cards[i].value = card::SIX; break;
        case 5: cards[i].value = card::SEVEN; break;
        case 6: cards[i].value = card::EIGHT; break;
        case 7: cards[i].value = card::NINE; break;
        case 8: cards[i].value = card::TEN; break;
        case 9: cards[i].value = card::JACK; break;
        case 10: cards[i].value = card::QUEEN; break;
        case 11: cards[i].value = card::KING; break;
        case 12: cards[i].value = card::ACE; break;
        }

        // Ustalanie koloru karty
        if (i >= 0 && i < numberOfCardsPerSuit) cards[i].suit = card::SPADE;
        else if (i >= numberOfCardsPerSuit && i < numberOfCardsPerSuit * 2) cards[i].suit = card::HEART;
        else if (i >= numberOfCardsPerSuit * 2 && i < numberOfCardsPerSuit * 3) cards[i].suit = card::CLUB;
        else if (i >= numberOfCardsPerSuit * 3 && i < numberOfCardsPerSuit * 4) cards[i].suit = card::DIAMOND;
    }
}

// Funkcja tasuje karty (pseudolosowoœæ)
void shuffleDeck(card* cards, int deckSize)
{
    for (int i = 0; i < deckSize; i++)
    {
        // Tymczasowa karta
        card tempCard = cards[i];
        int random = rand() % deckSize;

        // Typowa zamiana kart (swap)
        cards[i] = cards[random];
        cards[random] = tempCard;
    }
}

// Funkcja wypisuje kartê na ekran
void printSingleCard(struct card card)
{
    // Wypisanie wartoœci karty
    switch (card.value)
    {
    case card::TWO: cout << TWO_NAME; break;
    case card::THREE: cout << THREE_NAME; break;
    case card::FOUR: cout << FOUR_NAME; break;
    case card::FIVE: cout << FIVE_NAME; break;
    case card::SIX: cout << SIX_NAME; break;
    case card::SEVEN: cout << SEVEN_NAME; break;
    case card::EIGHT: cout << EIGHT_NAME; break;
    case card::NINE: cout << NINE_NAME; break;
    case card::TEN: cout << TEN_NAME; break;
    case card::JACK: cout << JACK_NAME; break;
    case card::QUEEN: cout << QUEEN_NAME; break;
    case card::KING: cout << KING_NAME; break;
    case card::ACE: cout << ACE_NAME; break;
    }

    // Jeœli nie jest to pusta karta, wypisuje spacjê,
    // czyli odstêp pomiêdzy kolorem a wartoœci¹.
    // Jeœli jest to pusta karta, wypisuje
    // sta³y string nadany dla pustej karty.
    if (isCardEmpty(card))
        cout << EMPTY_CARD_NAME;
    else
        cout << ' ';

    // Wypisanie koloru karty
    switch (card.suit)
    {
    case card::SPADE: cout << SPADE_NAME; break;
    case card::HEART: cout << HEART_NAME; break;
    case card::CLUB: cout << CLUB_NAME; break;
    case card::DIAMOND: cout << DIAMOND_NAME; break;
    }
}

// Wypisanie wszystkich kart znajduj¹cych siê w tablicy cards
void printCards(card* cards, int deckSize)
{
    for (int i = 0; i < deckSize; i++)
    {
        cout << '#' << i + 1 << ' ';
        printSingleCard(cards[i]);

        // Je¿eli nie jest do ostatnia karta, przejdŸ do nastêpnej linii
        if (i != deckSize - 1)
            cout << endl;
    }
}

// Ustawia karty w talii graczy tak, aby by³y pustymi kartami
void fillEmptyCards(card* handP1, card* handP2, int deckSize)
{
    for (int i = 0; i < deckSize; i++)
    {
        setCardEmpty(&handP1[i]);
        setCardEmpty(&handP2[i]);
    }
}

// Funkcja rozdaje graczom karty z tablicy cards
void dealCards(card* cards, card* handP1, card* handP2, int deckSize)
{
    for (int i = 0; i < deckSize; i++)
    {
        // Przyznaj najpierw karty pierwszemu graczowi
        if (i < (deckSize / 2))
            handP1[i] = cards[i];
        else
            handP2[i - (deckSize / 2)] = cards[i];
    }
}

// Funkcja przenosi wszystkie puste karty w talii gracza na koniec talii
void moveEmpty(card* hand, int deckSize)
{
    for (int i = 1; i < deckSize; i++)
    {
        for (int j = deckSize - 1; j >= 1; j--)
        {
            // Je¿eli karta jest pusta
            if (isCardEmpty(hand[j - 1]))
            {
                // Standardowy swap
                card tempCard = hand[j - 1];
                hand[j - 1] = hand[j];
                hand[j] = tempCard;
            }
        }
    }
}

// Funkcja zwracaj¹ca umown¹ wartoœæ karty na podstawie jej koloru i wartoœci
int handValue(card* hand, int deckSize)
{
    // Wartoœæ która zostanie zwrócona, na pocz¹tku równa 0
    int value = 0;

    for (int i = 0; i < deckSize; i++)
    {
        // Na podstawie wartoœci karty, przyznaj odpowiednie punkty
        switch (hand[i].value)
        {
        case card::TWO: value += 3; break;
        case card::THREE: value += 4; break;
        case card::FOUR: value += 5; break;
        case card::FIVE: value += 6; break;
        case card::SIX: value += 7; break;
        case card::SEVEN: value += 8; break;
        case card::EIGHT: value += 9; break;
        case card::NINE: value += 10; break;
        case card::TEN: value += 11; break;
        case card::JACK: value += 12; break;
        case card::QUEEN: value += 13; break;
        case card::KING: value += 14; break;
        case card::ACE: value += 15; break;
        }
    }

    return value;
}

// Funkcja przyznaje graczom karty "le¿¹ce na stole", np po wygranej wojnie
void assignCards(card* hand, card* cardsOnTableP1, card* cardsOnTableP2, int* P_CardsNumber, int* cardsOnTableNumberP1, int* cardsOnTableNumberP2)
{
    if ((*cardsOnTableNumberP1) > 0)
    {
        for (int i = 0; i < (*cardsOnTableNumberP1); i++)
        {
            hand[(*P_CardsNumber) + i] = cardsOnTableP1[i];
        }
        (*P_CardsNumber) += (*cardsOnTableNumberP1);
        (*cardsOnTableNumberP1) = 0;
    }

    if ((*cardsOnTableNumberP2) > 0)
    {
        for (int i = 0; i < (*cardsOnTableNumberP2); i++)
        {
            hand[(*P_CardsNumber) + i] = cardsOnTableP2[i];
        }
        (*P_CardsNumber) += (*cardsOnTableNumberP2);
        (*cardsOnTableNumberP2) = 0;
    }
}

// Funkcja wyœwietla menu tekstowe
void printMenu()
{
    cout << "  *******  MENU  *******  " << endl;
    cout << " 1. Rozegraj runde" << endl;
    cout << " 2. Koniec programu" << endl;
}

// Wyswietlenie informacji o stanie gry
void printGameInfo(bool ending, int P1_CardsNumber, int P2_CardsNumber, card* handP1, card* handP2, int turnCounter, int result, int deckSize)
{
    // Jesli jest to wyswietlenie informacji na koniec rundy
    if (ending)
    {
        cout << endl << "***** KONIEC *****" << endl;
        cout << endl << "Rozegrano tur: " << turnCounter << endl;

        switch (result)
        {
        case 1: cout << endl << "Wygral gracz numer 1!" << endl; break;
        case 2: cout << endl << "Wygral gracz numer 2!" << endl; break;
        case 3: cout << endl << "Remis!" << endl; break;
        }
    }

    cout << endl << "Liczba kart gracza 1: " << P1_CardsNumber << endl;
    cout << "Liczba kart gracza 2: " << P2_CardsNumber << endl;

    int handP1Value = handValue(handP1, P1_CardsNumber);
    int handP2Value = handValue(handP2, P2_CardsNumber);

    cout << endl << "Wartosc reki gracza 1: " << handP1Value << endl;
    cout << "Wartosc reki gracza 2: " << handP2Value << endl;

    cout << endl << "Reka gracza 1" << endl;
    if (ending)
        printCards(handP1, deckSize);
    else
        printCards(handP1, P1_CardsNumber);
    cout << endl << endl << "Reka gracza 2" << endl;
    if (ending)
        printCards(handP2, deckSize);
    else
        printCards(handP2, P2_CardsNumber);
    cout << endl << endl;
}

int main()
{
    // Generator liczb losowych
    srand((unsigned int)time(NULL));

    // Zmienne obslugujace menu
    bool exit = false;
    int opcja = 0;

    // Petla programu
    while (!exit)
    {
        system("cls");
        printMenu();
        cout << endl << "Wybierz opcje: ";

        // Jesli podana zostala litera
        if (!(cin >> opcja))
        {
            cin.clear();
            cin.ignore();
            continue;
        }

        cout << endl;
        switch (opcja)
        {
        case 1:
        {
            int deckSize;
            cout << "Podaj rozmiar talii (standardowo 52): ";
            cin >> deckSize;
            if (deckSize <= 0 || deckSize > 52)
            {
                cout << endl << "Nieprawidlowy rozmiar talii. Zaczynam rozgrywke ze standardowym rozmiarem" << endl;
                deckSize = 52;
            }

            // Ile kart jest w talii
            int numberOfCardsPerSuit = deckSize / 4;

            // Dynamiczna alokacja pamieci na talie i rece graczy
            card* cards = new card[deckSize];
            card* handP1 = new card[deckSize];
            card* handP2 = new card[deckSize];

            // Ile kart maja gracze
            int P1_CardsNumber = deckSize / 2;
            int P2_CardsNumber = deckSize / 2;
            int result = 0;
            int turnCounter = 0;

            // Utworzenie i przetasowanie talii
            createDeck(cards, deckSize, numberOfCardsPerSuit);
            shuffleDeck(cards, deckSize);

            // Utworzenie pustych miejsc i rozdanie kart
            fillEmptyCards(handP1, handP2, deckSize);
            dealCards(cards, handP1, handP2, deckSize);

            // Wyswietlenie informacji o stanie rak graczy przed rozpoczeciem rundy
            printGameInfo(false, P1_CardsNumber, P2_CardsNumber, handP1, handP2, turnCounter, result, deckSize);

            while (result == 0)
            {
                turnCounter++;

                card* cardsOnTableP1 = new card[deckSize];
                card* cardsOnTableP2 = new card[deckSize];

                int cardsOnTableNumberP1 = 0;
                int cardsOnTableNumberP2 = 0;

                int battleResult = 0;
                int warCounter = 0;

                while (battleResult == 0)
                {
                    if (isCardEmpty(handP1[0]) || isCardEmpty(handP2[0]))
                    {
                        if (isCardEmpty(handP1[0]) && !(isCardEmpty(handP2[0])))
                        {
                            assignCards(handP2, cardsOnTableP2, cardsOnTableP1, &P2_CardsNumber, &cardsOnTableNumberP2, &cardsOnTableNumberP1);
                            result = 2;
                            break;
                        }
                        else if (!(isCardEmpty(handP1[0])) && isCardEmpty(handP2[0]))
                        {
                            assignCards(handP1, cardsOnTableP1, cardsOnTableP2, &P1_CardsNumber, &cardsOnTableNumberP1, &cardsOnTableNumberP2);
                            result = 1;
                            break;
                        }
                        else if (isCardEmpty(handP1[0]) && isCardEmpty(handP2[0]))
                        {
                            result = 3;
                            break;
                        }
                    }

                    printSingleCard(handP1[0]);
                    cout << " vs ";
                    printSingleCard(handP2[0]);
                    cout << endl;

                    if (handP1[0].value > handP2[0].value)
                    {
                        struct card tempCardP1 = handP1[0];
                        struct card tempCardP2 = handP2[0];

                        setCardEmpty(&handP1[0]);
                        setCardEmpty(&handP2[0]);

                        moveEmpty(handP1, deckSize);
                        moveEmpty(handP2, deckSize);

                        // Sprawdza, czy zosta³y jakieœ karty na stole
                        if (cardsOnTableNumberP1 > 0)
                        {
                            for (int i = 0; i < cardsOnTableNumberP1; i++)
                            {
                                handP1[P1_CardsNumber - 1 + i] = cardsOnTableP1[i];
                            }
                            P1_CardsNumber += cardsOnTableNumberP1;
                            cardsOnTableNumberP1 = 0;
                        }
                        handP1[P1_CardsNumber - 1] = tempCardP1;

                        if (cardsOnTableNumberP2 > 0)
                        {
                            for (int i = 0; i < cardsOnTableNumberP2; i++)
                            {
                                handP1[P1_CardsNumber + i] = cardsOnTableP2[i];
                            }
                            P1_CardsNumber += cardsOnTableNumberP2;
                            cardsOnTableNumberP2 = 0;
                        }
                        handP1[P1_CardsNumber] = tempCardP2;

                        P1_CardsNumber++;
                        P2_CardsNumber--;

                        cout << "Wygrywa P1" << endl << endl;
                        battleResult = 1;
                        warCounter = 0;
                    }

                    else if (handP1[0].value < handP2[0].value)
                    {
                        struct card tempCardP1 = handP1[0];
                        struct card tempCardP2 = handP2[0];

                        setCardEmpty(&handP1[0]);
                        setCardEmpty(&handP2[0]);

                        moveEmpty(handP1, deckSize);
                        moveEmpty(handP2, deckSize);

                        if (cardsOnTableNumberP2 > 0)
                        {
                            for (int i = 0; i < cardsOnTableNumberP2; i++)
                            {
                                handP2[P2_CardsNumber - 1 + i] = cardsOnTableP2[i];
                            }
                            P2_CardsNumber += cardsOnTableNumberP2;
                            cardsOnTableNumberP2 = 0;
                        }
                        handP2[P2_CardsNumber - 1] = tempCardP2;

                        if (cardsOnTableNumberP1 > 0)
                        {
                            for (int i = 0; i < cardsOnTableNumberP1; i++)
                            {
                                handP2[P2_CardsNumber + i] = cardsOnTableP1[i];
                            }
                            P2_CardsNumber += cardsOnTableNumberP1;
                            cardsOnTableNumberP1 = 0;
                        }
                        handP2[P2_CardsNumber] = tempCardP1;

                        P1_CardsNumber--;
                        P2_CardsNumber++;

                        cout << "Wygrywa P2" << endl << endl;
                        battleResult = 2;
                        warCounter = 0;
                    }

                    // Wojna
                    else if (handP1[0].value == handP2[0].value)
                    {
                        cout << "Wojna!" << endl;

                        turnCounter++;

                        {
                            if (isCardEmpty(handP1[1]) || isCardEmpty(handP2[1]))
                            {
                                if (isCardEmpty(handP1[1]) && !(isCardEmpty(handP2[1])))
                                {
                                    cardsOnTableP1[cardsOnTableNumberP1] = handP1[0];
                                    cardsOnTableNumberP1++;
                                    P1_CardsNumber--;
                                    setCardEmpty(&handP1[0]);
                                    moveEmpty(handP1, deckSize);

                                    cardsOnTableP2[cardsOnTableNumberP2] = handP2[0];
                                    cardsOnTableNumberP2++;
                                    P2_CardsNumber--;
                                    setCardEmpty(&handP2[0]);
                                    moveEmpty(handP2, deckSize);

                                    result = 2;
                                    continue;
                                }
                                else if (!(isCardEmpty(handP1[1])) && isCardEmpty(handP2[1]))
                                {
                                    cardsOnTableP1[cardsOnTableNumberP1] = handP1[0];
                                    cardsOnTableNumberP1++;
                                    P1_CardsNumber--;
                                    setCardEmpty(&handP1[0]);
                                    moveEmpty(handP1, deckSize);

                                    cardsOnTableP2[cardsOnTableNumberP2] = handP2[0];
                                    cardsOnTableNumberP2++;
                                    P2_CardsNumber--;
                                    setCardEmpty(&handP2[0]);
                                    moveEmpty(handP2, deckSize);

                                    result = 1;
                                    continue;
                                }
                                else if (isCardEmpty(handP1[1]) && isCardEmpty(handP2[1]))
                                {
                                    result = 3;
                                    break;
                                }
                            }
                        }

                        cardsOnTableP1[cardsOnTableNumberP1] = handP1[0];
                        cardsOnTableP1[cardsOnTableNumberP1 + 1] = handP1[1];
                        cardsOnTableNumberP1 += 2;
                        P1_CardsNumber -= 2;

                        cardsOnTableP2[cardsOnTableNumberP2] = handP2[0];
                        cardsOnTableP2[cardsOnTableNumberP2 + 1] = handP2[1];
                        cardsOnTableNumberP2 += 2;
                        P2_CardsNumber -= 2;

                        setCardEmpty(&handP1[0]);
                        setCardEmpty(&handP1[1]);
                        setCardEmpty(&handP2[0]);
                        setCardEmpty(&handP2[1]);

                        moveEmpty(handP1, deckSize);
                        moveEmpty(handP2, deckSize);

                        //if(result > 0) break;
                    }
                    //end of while (battleResult == 0)
                }
                delete[] cardsOnTableP1;
                delete[] cardsOnTableP2;
            }
            printGameInfo(true, P1_CardsNumber, P2_CardsNumber, handP1, handP2, turnCounter, result, deckSize);

            delete[] cards;
            delete[] handP1;
            delete[] handP2;

            break;
        }
        case 2:
            exit = true;
            cout << "Nastepuje wyjscie z programu" << endl;
            break;
        default:
            cout << "Podano nieprawidlowa opcje!" << endl;
            break;
        }

        cout << endl << "Aby kontynuowac, nacisnij dowolny przycisk . . . ";
        (void)getchar();
        (void)getchar();
    }

    return 0;
};