#include "extrairediagonales.h"

ExtraireDiagonales::ExtraireDiagonales()
{
}


void ExtraireDiagonales::ExtraireToutesDiagonales(QList<InfoDiagonale> *listDiagonales,
                             QStringList *LesChaineADN,
                             int LongDiagoPermi)
 {
   /* les variable sont des variable de fonction car elle est statique
      on ne peut pas les mattre comme des variable de classe*/

    int Num_Sequence_Debut;/* pour parcurir tous les sequence
                                       qui sont dans LesChaineADN*/

    int Num_Sequence_Suivant; /* donc Num_Sequence_Debut pour la 1 premiere seq
                                        et Num_Sequence_Suivant pour la 2 eme*/

    int Debut_SousSequence1;/*le debut de la sous seq 1 qui est dans
                                         la seq Num_Sequence_Debut*/

    int Debut_SousSequence2;/*le debut de la sous seq 2 qui est dans
                                         la seq Num_Sequence_Suivant*/

    int i,j;/* pour parcurir les 2 sequence comme une matrice aprie
                        leur detrminison car on a Num_Sequence_Debut et Num_Sequence_Suivant
                                2 chaine de caractère le i pour parcurir la chaine Num_Sequence_Suivant
                                (pour parcourir les ligne)
                                et le j la chaine Num_Sequence_Debut*/

    int nbMatch;/* si "1" alors les caractère sont identique (Match)
                                "0" sino (misMatch)
                   donc la variable nbMatch va conti le nombre de similariter
                                   de caractère */

    int i_Similar;
    int j_Similar;
    // si on trouve une similariter entre 2 cara
    // on pourssui la recharche avec i_Similar j_Similar
    // pour gardi la trace de i et j et ça pour revenir a
    // la position (i+1 ou j+1) pour recharcher d'autre diagon
    // (similariti)

    int longDiagonale; // la longure d'une diagonale

    double poid_ac;// le poids des diagonal pour les accepti ou non


    int nbChaineADN=LesChaineADN->size ();



    for(Num_Sequence_Debut=0;Num_Sequence_Debut<(nbChaineADN -1);Num_Sequence_Debut++){
        for(Num_Sequence_Suivant=Num_Sequence_Debut+1;Num_Sequence_Suivant<nbChaineADN ;Num_Sequence_Suivant++)
        {

/* pour parcurir tous les sequence et tous les combinison sans redendance
   donc ces 2 premier boucle ser a choisir 2 sequence pour les traiter
   parmet l'ensemble des souquence cool.........wawe c'est gignale...*/

            QString Sequence_Debut=LesChaineADN->at(Num_Sequence_Debut);
            QString Sequence_Suivant=LesChaineADN->at(Num_Sequence_Suivant);

            int longSequence_Debut   =Sequence_Debut.size ();
            int longSequence_Suivant =Sequence_Suivant.size ();

            int arit_i=longSequence_Suivant-(LongDiagoPermi-1);
            // on met -(LongDiagoPermi-1) pour n'est pas aller a la fin de seq,
            // car les la longeur des diagonale sera < Longeure diagonale permet
            int arit_j=longSequence_Debut-(LongDiagoPermi-1);


            /// comme ça la Sequence_Debut sera la colone Sequence_Suivant sera la ligne
            /**    j
                   S e q u e n c e _ D e b u t
             i   S
                 e
                 q
                 _
                 S
                 u
                 i
                 v
                 a
                 n
                 t
            */

            // On va extraire les diagonales de la matrice haute
            // exemple : (les sequence n'ont pas les meme longeur)
            // 1 1 1 1 1 1 1 1 1 1
            //   1 1 1 1 1 1 1 1 1
            //     1 1 1 1 1 1 1 1
            //       1 1 1 1 1 1 1
            //         1 1 1 1 1 1
            //           1 1 1 1 1

            // exemple : (les sequence ont les meme longeur)
            // 1 1 1 1 1 1
            //   1 1 1 1 1
            //     1 1 1 1
            //       1 1 1
            //         1 1
            //           1

            // donc on comance toujour de le debut la ligne 0 (i=0)
            // et a chaque que on termine une diagonale on passe a la colone
            // prochaine (j=0 jusqu'à arit_j)


            i=0;
            for(j=0;j<arit_j;j++)
            {

                // dans une diagonale de la matrice on peut trouver
                // plusieurs diagonale(en sence DiAlign)
                // exemple: soit la diagonale matriciel i=0 et j=0
                // 1 (ok)
                //   1 (ok)
                //     1 (ok)
                //       0 ( no)
                //         0 ( no)
                //           1 (ok)
                //             1 (ok)
                //               1 (ok)

                // donc il nous faut une boucle pour ces diagonale (en sence DiAlign)
                // si on trouve une diagonale on la garde, ensuit on charche si
                // on trouve d'autre diagonale tell que sa longeur > longeurDiaPerm
                // donc si on arrive au (arit_i ou arit_j) on arrite la recharche
                // des similitude car on sur que la diagonale qu'on va trouves
                // a une longeur < LongDiagPerm

                i_Similar=i;
                j_Similar=j;
                // pour cet boucle on utilise i_Smilar et j_Smilar pour
                // garder la trace pour traiter les autre diagonale.

                while( i_Similar<arit_i && j_Similar<arit_j)
                {

                    ///////////////////////////////////////////////////////////
                    //si on a une relation entre les 2 cara
                    if ( comp(Sequence_Debut.at(j_Similar),Sequence_Suivant.at(i_Similar)) == 1 )
                    {
                        Debut_SousSequence1=j_Similar; // j le debut de la sous seq 1
                        Debut_SousSequence2=i_Similar; // i le debut de la sous seq 2

                        nbMatch=simi(Sequence_Debut.at(j_Similar),Sequence_Suivant.at(i_Similar));
                        // nbMatch==1 ou 0

                         i_Similar++;
                         j_Similar++;
                         // pour passer à le test au cara suivant

                         // on a trouver 1 cara donc on va poursuive la virification
                         // pour les autres cara pour identifier la diagonale
                         // on poursuive la recharche jusqu'à la fin des sequence

                         while( (i_Similar<longSequence_Suivant) && (j_Similar<longSequence_Debut ) )
                         {
                             if( comp(Sequence_Debut.at(j_Similar),Sequence_Suivant.at(i_Similar)) == 1 )
                             {

                                nbMatch += simi(Sequence_Debut.at(j_Similar),Sequence_Suivant.at(i_Similar));

                                i_Similar++;
                                j_Similar++;   // pour passer a la case suivant
                             }
                             else break;

                         }//fin de comparison de la boucle while

                         longDiagonale = j_Similar-Debut_SousSequence1;
                         // si la meme chose si on fais i-Debut_SousSequence2

                         if( longDiagonale >= LongDiagoPermi )
                         {
                             // si on a une long acceptable alors
                             // on calcule le poid de diagonal

                             poid_ac=PoidsDiagonale::calcule_poids(longDiagonale,nbMatch,longSequence_Debut,longSequence_Suivant);

                             if( poid_ac>=0 )
                             {
                                 // si la longeur de diagonale et son poid est acceptable donc
                                 // on sauvgarde leur info dans listDiagonales

                                 listDiagonales->append(
                                         InfoDiagonale(
                                                 Debut_SousSequence1,(j_Similar-1),// debut,Fin_SousSequence1
                                                 Debut_SousSequence2,(i_Similar-1),// debut,Fin_SousSequence2
                                                 Num_Sequence_Debut,       // Num_Sequence1
                                                 Num_Sequence_Suivant,     // Num_Sequence2
                                                 longSequence_Debut-1,     // Fin_Sequence1
                                                 longSequence_Suivant-1,   // Fin_Sequence2
                                                 poid_ac                   // le poids e diagonale
                                                 )
                                         );

                                 }
                             }

                   }//fin de if comp(les 2 premier caractere)
                   ///////////////////////////////////////////////////////

                    // on arrive a ce point(cette ligne de code)
                    // a cause de 2 chose:
                    //                    1) on arriver a la fin donc
                    //                       les similitude sont jusqu'a la fin
                    //                    2) on rencontrer une dissimilitude
                    // dans les 2 cas on passe au caractere suivant pour continuer
                    // le traitement.
                    i_Similar++;
                    j_Similar++;

                }

            }


            // et maintenant on fait le meme tratement pour la partie
            // inferieur de la matrice.
            // on comance du la ligne n=1 (i=1) car on déja triter
            // la diagonale principale (i=0,j0) dans la première partie
            // exemple : (les sequence n'ont pas les meme longeur)
            // 1 1 1 1 1 1 1 1 1 1
            // 0 1 1 1 1 1 1 1 1 1
            // 0 0 1 1 1 1 1 1 1 1
            // 0 0 0 1 1 1 1 1 1 1
            // 0 0 0 0 1 1 1 1 1 1
            // 0 0 0 0 0 1 1 1 1 1

            // le traitement va concerné que la partie inferieur
            // donc la partie qui contien les zéro

            // exemple : (les sequence ont les meme longeur)
            // 1 1 1 1 1 1
            // 0 1 1 1 1 1
            // 0 0 1 1 1 1
            // 0 0 0 1 1 1
            // 0 0 0 0 1 1
            // 0 0 0 0 0 1

            // donc  la on change : le i commence de 1 jusqu'à arit_i
            // et le j rest toujour a 0.

            j=0;
            for(i=1;i<arit_i;i++)
            {

                // dans une diagonale de la matrice on peut trouver
                // plusieurs diagonale(en sence DiAlign)
                // exemple: soit la diagonale matriciel i=0 et j=0
                // 1 (ok)
                //   1 (ok)
                //     1 (ok)
                //       0 ( no)
                //         0 ( no)
                //           1 (ok)
                //             1 (ok)
                //               1 (ok)

                // donc il nous faut une boucle pour ces diagonale (en sence DiAlign)
                // si on trouve une diagonale on la garde, ensuit on charche si
                // on trouve d'autre diagonale tell que sa longeur > longeurDiaPerm
                // donc si on arrive au (arit_i ou arit_j) on arrite la recharche
                // des similitude car on sur que la diagonale qu'on va trouves
                // a une longeur < LongDiagPerm

                i_Similar=i;
                j_Similar=j;
                // pour cet boucle on utilise i_Smilar et j_Smilar pour
                // garder la trace pour traiter les autre diagonale.

                while( i_Similar<arit_i && j_Similar<arit_j)
                {

                    ///////////////////////////////////////////////////////////
                    //si on a une relation entre les 2 cara
                    if ( comp(Sequence_Debut.at(j_Similar),Sequence_Suivant.at(i_Similar)) == 1 )
                    {
                        Debut_SousSequence1=j_Similar; // j le debut de la sous seq 1
                        Debut_SousSequence2=i_Similar; // i le debut de la sous seq 2

                        nbMatch=simi(Sequence_Debut.at(j_Similar),Sequence_Suivant.at(i_Similar));
                        // nbMatch==1 ou 0

                         i_Similar++;
                         j_Similar++;
                         // pour passer à le test au cara suivant

                         // on a trouver 1 cara donc on va poursuive la virification
                         // pour les autres cara pour identifier la diagonale
                         // on poursuive la recharche jusqu'à la fin des sequence

                         while( (i_Similar<longSequence_Suivant) && (j_Similar<longSequence_Debut ) )
                         {
                             if( comp(Sequence_Debut.at(j_Similar),Sequence_Suivant.at(i_Similar)) == 1 )
                             {

                                nbMatch += simi(Sequence_Debut.at(j_Similar),Sequence_Suivant.at(i_Similar));

                                i_Similar++;
                                j_Similar++;   // pour passer a la case suivant
                             }
                             else break;

                         }//fin de comparison de la boucle while

                         longDiagonale = j_Similar-Debut_SousSequence1;
                         // si la meme chose si on fais i-Debut_SousSequence2

                         if( longDiagonale >= LongDiagoPermi )
                         {
                             // si on a une long acceptable alors
                             // on calcule le poid de diagonal

                             poid_ac=PoidsDiagonale::calcule_poids(longDiagonale,nbMatch,longSequence_Debut,longSequence_Suivant);

                             if( poid_ac>=0 )
                             {
                                 // si la longeur de diagonale et son poid est acceptable donc
                                 // on sauvgarde leur info dans listDiagonales

                                 listDiagonales->append(
                                         InfoDiagonale(
                                                 Debut_SousSequence1,(j_Similar-1),// debut,Fin_SousSequence1
                                                 Debut_SousSequence2,(i_Similar-1),// debut,Fin_SousSequence2
                                                 Num_Sequence_Debut,       // Num_Sequence1
                                                 Num_Sequence_Suivant,     // Num_Sequence2
                                                 longSequence_Debut-1,     // Fin_Sequence1
                                                 longSequence_Suivant-1,   // Fin_Sequence2
                                                 poid_ac                   // le poids e diagonale
                                                 )
                                         );

                                 }
                             }

                   }//fin de if comp(les 2 premier caractere)
                   ///////////////////////////////////////////////////////

                    // on arrive a ce point(cette ligne de code)
                    // a cause de 2 chose:
                    //                    1) on arriver a la fin donc
                    //                       les similitude sont jusqu'a la fin
                    //                    2) on rencontrer une dissimilitude
                    // dans les 2 cas on passe au caractere suivant pour continuer
                    // le traitement.
                    i_Similar++;
                    j_Similar++;

                }

            }



        ////////////////
        }
    }// fin de tratement pour toutes les sequences donner



}

int ExtraireDiagonales::comp(QChar x,QChar y)
{
    if(x==y||(x=='A'&& y=='T')||(x=='C'&& y=='G')||(x=='T'&& y=='A')||(x=='G'&& y=='C'))
    {
        return (1);
    }

    return (0);
}

int ExtraireDiagonales::simi(QChar s1,QChar s2)
{
    if(s1==s2)return 1;

    return 0;
}

