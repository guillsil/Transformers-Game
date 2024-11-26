#include "../include/GraficadorCombates.hpp"

GraficadorCombates:: GraficadorCombates(){}

GraficadorCombates:: ~GraficadorCombates(){}

void GraficadorCombates:: vertices_dobles(size_t valor1, size_t valor2){
    string pre_espaciado = "   ";
    string post_espaciado = "   ";
    if(valor1 > 99 || valor2 > 99){
        pre_espaciado = "  ";
        post_espaciado = "  ";
    }
    else if(valor1 > 10 || valor2 > 10){
        pre_espaciado = "  ";
        post_espaciado = "   ";
    }
    cout << "  °°°°°       °°°°°"
    <<endl<<" °     °     °     °"
    <<endl<<"°"<< pre_espaciado << valor1 << post_espaciado << "°   " 
    <<"°"<< pre_espaciado << valor2 << post_espaciado << "°"
    <<endl<<" °     °     °     °"
    <<endl<<"  °°°°°       °°°°°" << endl;
}

void GraficadorCombates:: vertices_triples(size_t valor1, size_t valor2, size_t valor3){
    string pre_espaciado = "   ";
    string post_espaciado = "   ";
    if(valor1 > 99 || valor2 > 99 || valor3 > 99){
        pre_espaciado = "  ";
        post_espaciado = "  ";
    }
    else if(valor1 > 10 || valor2 > 10 || valor3 > 10){
        pre_espaciado = "  ";
        post_espaciado = "   ";
    }
    cout << "  °°°°°       °°°°°       °°°°°"
    <<endl<<" °     °     °     °     °     °"
    <<endl<<"°"<< pre_espaciado << valor1 << post_espaciado << "°   " 
    <<"°"<< pre_espaciado << valor2 << post_espaciado << "°   "
    <<"°"<< pre_espaciado << valor3 << post_espaciado << "°"
    <<endl<<" °     °     °     °     °     °"
    <<endl<<"  °°°°°       °°°°°       °°°°°" << endl;
}

void GraficadorCombates:: vertice_individual(string valor){
    string pre_espaciado = "   ";
    string post_espaciado = "   ";
    if(valor.length() > 6){
        pre_espaciado = "";
        post_espaciado = "";
    }
    else if(valor.length() >= 2){
        pre_espaciado = "  ";
        post_espaciado = "   ";
    }
    cout << "              °°°°°"
    <<endl<<"             °     °"
    <<endl<<"            °" << pre_espaciado << valor << post_espaciado << "°" 
    <<endl<<"             °     °"
    <<endl<<"              °°°°°" << endl;
}

void GraficadorCombates:: vertice_individual(size_t valor){
   vertice_individual(to_string(valor));
}

string GraficadorCombates:: acotar_nombre(string nombre){
    string nombre_acotado = "OP";
	if(nombre == "Megatron") nombre_acotado = "M";
	return nombre_acotado;
}

void GraficadorCombates:: mostrar_mapa_combates(Vector<Transformers>& transformers_en_mapa){
	size_t transformers_secundarios = transformers_en_mapa.tamanio() -2;
    size_t cant_tres_vertices = transformers_secundarios / 3;
    size_t vertices_sueltos = transformers_secundarios % 3; //Siempre seran 0, 1 o 2

    vertice_individual(acotar_nombre(transformers_en_mapa[0].obtener_nombre()));
    if(cant_tres_vertices == 0){
        switch (vertices_sueltos){
            case 0:
                cout << union_unica << endl;
                break;
            case 1:
                cout << union_unica << endl;
                vertice_individual(1);
                cout << union_unica << endl;
                break;
            default:
                cout << union_uno_dos << endl;
                vertices_dobles(1,2);
                cout << union_dos_uno << endl;
                break;
        }
    }  
    else {
        cout << union_uno_tres << endl;
        vertices_triples(1,2,3);
        size_t j = 4;
        for(size_t i = 0; i < cant_tres_vertices -1; i++){
            cout << union_tres_tres << endl;
            vertices_triples(j,j+1,j+2);
            j += 3;
        }
        switch(vertices_sueltos){
            case 0:
                cout << union_tres_uno << endl;
                break;
            case 1:
                cout << union_tres_uno << endl;
                vertice_individual(j);
                cout << union_unica << endl;
                break;
            default:
                cout << union_tres_dos << endl;
                vertices_dobles(j,j+1);
                cout << union_dos_uno << endl;
                break;
        }
    }
    vertice_individual(acotar_nombre(transformers_en_mapa[transformers_en_mapa.tamanio()-1].obtener_nombre()));
}

void GraficadorCombates:: mostrar_secuencia(Vector<size_t>& secuencia, Transformers& p_principal, Transformers& j_final){
	vertice_individual(acotar_nombre(p_principal.obtener_nombre()));
	for(size_t i = 1; i < secuencia.tamanio()-1; i++){
        cout << union_unica << endl;
        vertice_individual(secuencia[i]);
	}
    cout << union_unica << endl; 
    vertice_individual(acotar_nombre(j_final.obtener_nombre()));
}