#include<stdio.h>
#include<string.h>
#include "cldi.h"

String genreTable[16] = {
    "Ballad", "Pop Rock", "Pop", "R&B", "Rock", "Country Pop", "J-Pop", "K-Pop",
    "Classical", "Theater", "EDM", "OPM", "Reggae","Dance", "Jazz",  "Indie"
};

//Write your functions here...
void insert(VirtualHeap *VH,Song song) {
    int hashIdx;

    hashIdx = hash(song.genre);
    
    if(strcmp(VH->H[hashIdx].elem.genre, "Empty") == 0) {
        
         strcpy(VH->H[hashIdx].elem.genre, song.genre);
         strcpy(VH->H[hashIdx].elem.singer, song.singer);
         strcpy(VH->H[hashIdx].elem.songName, song.songName); 
         VH->H[hashIdx].next = -1;
         
    } else {
        int newIdx = VH->avail;
        VH->avail = VH->H[newIdx].next;
        
        strcpy(VH->H[newIdx].elem.genre, song.genre);
        strcpy(VH->H[newIdx].elem.singer, song.singer);
        strcpy(VH->H[newIdx].elem.songName, song.songName);
        VH->H[newIdx].next = -1;
        
        int trav = hashIdx;
        while(VH->H[trav].next != -1) {
            trav = VH->H[trav].next;
        }
        VH->H[trav].next = newIdx;
        
        return;
    }
}

void deleteMember(VirtualHeap *VH, Song song) {
    int hashIdx = hash(song.genre);

    int prev = -1;
    int trav = hashIdx;

    while (trav != -1) {
        if (strcmp(VH->H[trav].elem.songName, song.songName) == 0) {

            if (prev == -1) {

                if (VH->H[trav].next == -1) {
                    
                    strcpy(VH->H[trav].elem.genre, "Empty");
                    strcpy(VH->H[trav].elem.singer, "");
                    strcpy(VH->H[trav].elem.songName, "");
                } else {

                    int nextIdx = VH->H[trav].next;
                    VH->H[trav].next = VH->H[nextIdx].next;

                    VH->H[trav].elem = VH->H[nextIdx].elem;

                    VH->H[nextIdx].next = VH->avail;
                    VH->avail = nextIdx;
                }
            } else {
                
                VH->H[prev].next = VH->H[trav].next;

                strcpy(VH->H[trav].elem.genre, "Empty");
                strcpy(VH->H[trav].elem.singer, "");
                strcpy(VH->H[trav].elem.songName, "");
                VH->H[trav].next = VH->avail;
                VH->avail = trav;
            }
            return;
        }
        prev = trav;
        trav = VH->H[trav].next;
    }

}


int search(VirtualHeap VH,Song song) {
    int hashIdx = hash(song.genre);
    int trav = hashIdx;
    
    while(trav != -1) {
        if(strcmp(VH.H[trav].elem.songName, song.songName) == 0) {
            return 1;
        }
        trav = VH.H[trav].next;
    }
    
    return 0;
}

int hash(String genre) {
    int i=0;

    for(; i<16; i++) {
        if(strcmp(genreTable[i], genre) == 0) {
            return i;
        }
    }
    return -1;
}