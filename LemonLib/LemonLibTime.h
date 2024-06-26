#include <ctime>

time_t now = time(0);
tm *ltm = localtime(&now);

// Estas son funciones que obtienen el tiempo usando la libreria ctime y el UNIX timestamp
// que el unix es una cosa que va contando cada segundo desde 1 de enero 1970 que quieren que les diga
// gracias a esta pagina que es donde saque las convalencias:
// https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm

// Asi no me pueden engañar cambiando la fecha de su computador CABRONES

namespace LLT {

    void update_timer() { now = time(0); ltm = localtime(&now); }
    time_t getUNIX() { return time(0); }

    int year() { update_timer(); return (1900 + ltm->tm_year); }
    int month() { update_timer(); return (1 + ltm->tm_mon); }
    int day() { update_timer(); return (ltm->tm_mday); }
    int hour() { update_timer(); return (ltm->tm_hour); }
    int minute() { update_timer(); return(ltm->tm_min); }
    int second() { update_timer(); return(ltm->tm_sec); }

    int yearUNIX(time_t unix) { ltm = localtime(&unix); return (1900 + ltm->tm_year); }
    int monthUNIX(time_t unix) { ltm = localtime(&unix); return (1 + ltm->tm_mon); }
    int dayUNIX(time_t unix) { ltm = localtime(&unix); return (ltm->tm_mday); }
    int hourUNIX(time_t unix) { ltm = localtime(&unix); return (ltm->tm_hour); }
    int minuteUNIX(time_t unix) { ltm = localtime(&unix); return(ltm->tm_min); }
    int secondUNIX(time_t unix) { ltm = localtime(&unix); return(ltm->tm_sec); }

}

#ifdef NAMESPACE_TOTALITY
    using namespace LLT;
#endif