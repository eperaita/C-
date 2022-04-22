
//Diferencias entre ABSTRACT CLASS y INTERFACE
//
//Cuales necesitan virtual 
//PROBLEMAS ENCONTRADOS	
//- no me deja destruir un Ice/Cure porque acude al destructor de Amateria, porque estan aojados en un puntero base, pero tengo que hacer delete de ellos usando su propio destructr. Me dice que ponga virtual
//- Dependencias circulares: Amateria necesita de Icharacter y Icharacter necesita de AMateria. COmo solucionarlo? Declarar que existe class ICharacter antes de prototipar Amateria, y luego añadir el include abajo, para que copie la defiicion de un Icharacter.(que ya lo incluye el cpp) 
//
//// why need to declare a method in a inherited class?
// Because virtual method forces to redefine them by the child classes.
