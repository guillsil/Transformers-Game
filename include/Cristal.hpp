#ifndef CRISTAL_HPP
#define CRISTAL_HPP

enum Rareza {
    COMUN,
    RARO,
    EPICO,
    LEGENDARIO
};

class Cristal {
public:
    Cristal();

    Cristal(Rareza rareza);

    bool operator==(Rareza rareza);
};

#endif
