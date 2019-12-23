#include<iostream>
#include <stack>
#include <conio.h>
using namespace std;

class Simpul
{
public:
	int iData;
	double dData;
	Simpul* pAnakKiri;
	Simpul* pAnakKanan;
	
	Simpul():iData(0),dData(0.0), pAnakKiri(NULL),pAnakKanan(NULL){}
	~Simpul()
	{cout<<"X-"<<iData<<" ";}
	void tampilSimpul()
	{
		cout<<"{"<<iData<<","<<dData<<"}";
	}
};
class Pohon
{
private:
	Simpul* pAkar;
public:
	Pohon():pAkar(NULL)
	{}
	Simpul* cari(int kunci){
	Simpul* pSkrg=pAkar;
	while(pSkrg->iData!=kunci){
	if(kunci<pSkrg->iData)
		pSkrg=pSkrg->pAnakKiri;
	else
		pSkrg=pSkrg->pAnakKanan;

	if (pSkrg==NULL)
	return NULL;
	}
	return pSkrg;
}
	void sisip(int id, double dd) //menyisipkan simpul baru 
	{ 
		Simpul* SimpulBaru = new Simpul; //menciptakan simpul baru 
		SimpulBaru->iData = id; //menyisipkan data 
		SimpulBaru->dData = dd; 
		if(pAkar==NULL) //tidak ada simpul pada akar 
			pAkar = SimpulBaru; 
		else //akar ditempati
	{
		Simpul* pSkrg = pAkar; //diawali di akar 
		Simpul* pInduk; 
		while(true){
	 	//(keluar scr internal) 
			pInduk = pSkrg; 
			if(id < pSkrg->iData) //ke kiri? 
			{
				pSkrg = pSkrg->pAnakKiri; 
				if(pSkrg == NULL) //jika di akhir, 
				{
					pInduk->pAnakKiri=SimpulBaru;
					return;
				}
			}
			else //atau kanan?
			{
				pSkrg=pSkrg->pAnakKanan;
				if(pSkrg==NULL){
					pInduk->pAnakKanan=SimpulBaru;
					return;
				}
			}//akhir else ke kanan 
		}//akhir while	
	}//akhir else tidak akar
}//akhir sisip()

void jelajah(int tipeJelajah){
	switch(tipeJelajah) {
		case 1: cout << "InPenjelajahan Preorder: "; 
				preOrder(pAkar); 
				break; 
		case 2: cout << "InPenjelajahan Inorder: "; 
				inOrder(pAkar); 
				break; 
		case 3: cout << "InPenjelajahan Postorder: "; 
				postOrder(pAkar); 
				break;
	}
	cout<<endl;
}
void preOrder(Simpul* pAkarLokal){
	if(pAkarLokal != NULL){
		cout << "pAkarLokal->IData <"; //menampilkan simpul 
		preOrder(pAkarLokal->pAnakKiri); //anak kiri 
		preOrder(pAkarLokal->pAnakKanan); //anak kanan 
	}
}
void inOrder(Simpul* pAkarLokal) {
	if(pAkarLokal != NULL) 
	{
		inOrder(pAkarLokal->pAnakKiri); //anak kiri 
		cout << pAkarLokal->iData << " "; //menampilkan simpul 
		inOrder(pAkarLokal->pAnakKanan); //anak kanan 
	}
}
void postOrder(Simpul* pAkarLokal) {
	if(pAkarLokal != NULL) {
		postOrder(pAkarLokal->pAnakKiri); //anak kiri 
		postOrder(pAkarLokal->pAnakKanan); //anak kanan 
		cout << pAkarLokal->iData << ""; //menampilkan simpul
	} 
}
void tampilPohon() {
	stack<Simpul*> tumpukan; 
	tumpukan.push(pAkar); 
	int jumSpasi = 32; 
	bool apaBarisKosong = false; 
	 cout <<"........................";
	 cout << endl; 
	 while(apaBarisKosong==false){
	 	stack<Simpul*> tumpukanLokal; 
	 	apaBarisKosong = true; 

	 	for(int j=0; j<jumSpasi; j++) 
	 		cout << " "; 

	 	while(tumpukan.empty()==false) {
	 		Simpul* temp = tumpukan.top(); 
	 		tumpukan.pop(); 

	 		if(temp != NULL) { 
	 			cout << temp->iData; 
	 			tumpukanLokal.push(temp->pAnakKiri); 
	 			tumpukanLokal.push(temp->pAnakKanan); 

	 			if(temp->pAnakKiri != NULL || temp->pAnakKanan!=NULL)
	 				{apaBarisKosong=false;}
	 			else
	 				{
	 					cout<<"---";
	 					tumpukanLokal.push(NULL);
	 					tumpukanLokal.push(NULL);
	 				}
	 		}
	 	}
	 	cout <<endl;
	 	jumSpasi/=2;

	 	while(tumpukanLokal.empty()==false){
	 		tumpukan.push(tumpukanLokal.top());
	 		tumpukanLokal.pop();
	 	}
	}
	cout<<"..................";
	cout<<endl;
}//akhir tampilPohon()
void hapus() //menghapus semua simpul 
{ hapusRekursif(pAkar);} //mulai dari akar 

void hapusRekursif(Simpul* pAkarLokal) //menghapus simpul-simpul 
{
	if(pAkarLokal != NULL) 
	{ 
		hapusRekursif(pAkarLokal->pAnakKiri); //subpohon kiri 
		hapusRekursif(pAkarLokal->pAnakKanan); //subpohon kanan 
		delete pAkarLokal; //menghapus simpul ini 
	}
}
}; //akhir kelas Pohon 

int main(){
 	int nilai; 
 	char pilihan=0; 
 	Simpul* ditemukan;

 	Pohon pohon;//menciptakan pohon

 	pohon.sisip(50, 5.0); //menyisipkan pohon-pohon 
	pohon.sisip(25, 2.5); 
	pohon.sisip(75, 7.5); 
	pohon.sisip(12, 1.2); 
	pohon.sisip(37, 3.7); 
	pohon.sisip(43, 4.3); 
	pohon.sisip(30, 3.0); 
	pohon.sisip(33, 3.3); 
	pohon.sisip(87, 8.7); 
	pohon.sisip(93, 9.3); 
	pohon.sisip(97, 9.7); 

	while(pilihan != 'k') //berinteraksi dengan pengguna 
	{ //sampai pengguna mengetikkan 'k' 
		cout << "masukkan huruf pertama dari "; 
		cout << "tampil, sisip, cari, jelajah, atau keluar: "; 
		cin >> pilihan; 
		switch(pilihan){
			case 't': //menampilkan Pohon
						pohon.tampilPohon(); 
						break; 
			case 's': //menyisipkan sebuah Simpul 
						cout << "Masukkan nilai yang akan disisipkan: "; 
						cin >> nilai; 
						pohon.sisip(nilai, nilai + 0.9); 
						break; 
			case 'c': //mencari sebuah Simpul 
						cout << "Masukkan nilai yang akan dicari: "; 
						cin >> nilai; 
						ditemukan = pohon.cari(nilai); 
						if(ditemukan != NULL) {
							cout << "Ditemukan: "; 
							ditemukan->tampilSimpul(); 
							cout << endl; 
						}else
							cout << "Tidak ditemukan." << nilai << endl; 
							break; 
			case 'j': //menjelajah Pohon 
						cout << "Masukkan tipe jelajah (1 preorder, " << "2 = inorder, 3 = postorder): "; 
						cin >> nilai; pohon.jelajah(nilai); 
						break;
			case 'k': //keluar program 
						pohon.hapus(); 
						cout << endl; 
						break; 
			default: cout << "Entri tak-valid\n"; 
		} //akhir switch 
	} //akhir while 
	getch(); 
	return 0; 
} //akhir main()
