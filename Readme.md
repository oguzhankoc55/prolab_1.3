# Prolab1 3.Proje

# BAĞLI LİSTE İLE KELİME SAYMA

# Problem Tanımı

Bize verilen metin belgesi içerisindeki kelimeleri dizi kullanmadan kelimelerin metin içindeki tekrar sayısı değerlerinin büyüklüklerine göre sıralanması ve anlık olarak oluşturulan bağlı listeye eklenmesi istenmektedir.
## Yapılan araştırmalar

- Projede kullanmamız gereken konu ve yöntemlere karar verdik.
- Bağlantılı liste hakkında araştırmalar yaptık.
- Verilen dosyadaki metini dizi kullanmadan almakta ve kıyaslamada sıkıntı yaşadık.
- Alınan metni stdlib.h kütüphanesindeki malloc fonksiyonu kullanılarak bellekte metnin tutulabileceği bir yer ayırdık. fgets() fonksiyonu kullanılarak metni kopyaladık.
- Alınan metindeki kelimeleri ayırırken sıkıntı yaşadık.Alınan metni string.h kütüphanesindeki strtok() fonksiyonu kullanılarak kelimelere ve işaretlere ayırdık. Alınan kelimeleri malloc fonksiyonu kullanılarak bellekte tuttuk.
- Alınan kelimelerin metindeki sayılarının bulunmasında sıkıntı yaşadık.Metindeki kelimelerin adet sayılarını bulurken kullandığımız iç içe yerleştirdiğimiz döngüler kıyaslama ve sayma yaparken gönderilen adresler de karışma oluyordu .Bu hatalardan kurtulmak için kelimelerin karşılaştırılmasında kullanmak için yeni bir metin belgesi oluşturduk ve metni değiştirerek yeni metin belgesine kaydettik.
- Bağlı listeyi oluştururken eklenen kelimelerin tekrar etmelerini önlemekte sıkıntı yaşadık.Kelimelerin tekrar etmelerini önlemek için bağlı listeyi dolaşan ve alınan kelimeyle kıyaslayan bir fonksiyon yazdık.
- Bağlı listeyi oluştururken kelimelerin adet sayılarını kıyaslanması ve konumlarının bulunmasında sıkıntı yaşadık.Kelimelerin tekrar sayıları ve bağlı listede bulunmadıkları kontrol eden bir fonksiyon yazdık.

# Tasarım

# Akış Şeması

![image](https://user-images.githubusercontent.com/58952369/180408345-1a09bcd2-a5f7-431b-9337-13f9c826b73b.png)


# Yazılım Mimarisi

## 1- Düğüm İşlemleri
Projede yapmak istediğimiz metinde geçen kelimelerin adet sayılarına göre bağlı listedeki düğümlerde sıralamaktır. Bu işlemi yaparken her düğümü temsil eden bir struct kullandık. Bu struct içinde S_kelime adında kelimenin adresinin tutulduğu pointer ,bir sonraki düğümün adresini tutan kendi tipinden olan sonraki adlı pointer ve kelimenin metinde bulunma sıklığını tutan adet isimli integer tipinde değişkenimiz bulunmaktadır.Düğümü gösteren struct aşağıdaki şekildeki gibidir.

![image](https://user-images.githubusercontent.com/58952369/180408400-97795566-38c4-4523-9699-b4871bf550b5.png)

## 2- Fonksiyonlar
### void ekle(char *kelime) fonksiyonu:
Fonksiyonumuzun başlangıcında alınan pointerın adresinde bulunan kelimenin ozelMi fonksiyonu ile bağlı listede bulunup bulunmadığının kontrolü yapılır.Alınan kelimenin adet sayısının integer olarak tutulan enBuyuk ve enKucuk değerleriyle kıyaslanarak kelimenin basaEkle,sonaEkle veya arayaEkle fonksiyonlarından birine
gönderilmesi sağlanarak bağlı listeye eklenir.

![image](https://user-images.githubusercontent.com/58952369/180408964-415cd124-11a2-4989-b0c3-f7df0aed5bdd.png)


### int say(char * deneme1) fonksiyonu: 
Fonksiyonumuzun başında metin belgesinden okuma yapılır. Kullandığımız malloc fonksiyonu ile bellekten yer ayırılır. Ayırdığımız alana metin belgesinde bulunan metini kopyalanır. Say fonksiyonuna gönderilen pointer ile metin belgesindeki ayrılan kelimeler while döngüsü içinde karşılaştırılarak sayaç yardımıyla kelimenin metin içinde kaç adet olduğu bulunur ve return edilir.

![image](https://user-images.githubusercontent.com/58952369/180409037-e88f285c-4e35-43b4-bae6-5ea41f446be8.png)


### int ozelMi(char *kelime) fonksiyonu: 
Fonksiyonumuzda bağlı listede bulunan düğümlerdeki S_kelime ile fonksiyona gönderilen kelime pointerının tuttukları adreslerdeki kelimeler karşılaştırılır.Kelimeler eşitse 0 değeri return edilir,değilse 1 değeri return edilir.Böylece aynı kelimenin tekrarından kaçınılmış olunur.

![image](https://user-images.githubusercontent.com/58952369/180409155-061a3760-863d-4e7d-b642-6d1ce4564200.png)

### void basaEkle(char *kelime) fonksiyonu: 
Metinden aldığımız kelimenin adet sayısı bağlı listenin başlangıcındaki düğümde bulunan adet sayısından büyük ise kelime bağlı listenin başlangıç
konumuna yerleştirilmesi için başaEkle fonksiyonuna gönderilir.Fonksiyonumuzda yeni bir düğüm oluşturulur ve bağlı listenin başlangıç konumuna yerleştirilir.

![image](https://user-images.githubusercontent.com/58952369/180409214-c3b3ee64-c123-457b-998a-103894222518.png)


### void arayaEkle(char *kelime) fonksiyonu: 
Metinden aldığımız kelimenin adet sayısı bağlı listenin başlangıcındaki düğümde bulunan adet sayısından küçük ise ve integer olarak tutulan enKucuk değerinden büyük ise kelimenin adresi fonksiyona gönderilir.Fonksiyonumuzda yeni bir düğüm oluşturulur ve düğümün yerinin bulunması için bağlı listede karşılaştırılma yapılır.Bulunan konuma düğüm yerleştirilir.

![image](https://user-images.githubusercontent.com/58952369/180409241-78d3b4b4-9dcb-404c-894d-8778e8bae32d.png)

### void sonaEkle(char *kelime) fonksiyonu: 

Metinden aldığımız kelimenin adet sayısı integer olarak tutulan enKucuk değerinden küçük ise kelime bağlı listenin bitiş konumuna yerleştirilmesi için sonaEkle fonksiyonuna gönderilir.Fonksiyonumuzda yeni bir düğüm oluşturulur ve bağlı listenin bitiş konumuna yerleştirilir.

![image](https://user-images.githubusercontent.com/58952369/180409292-35bc8f8c-05a0-4c20-a60d-d2182a10050e.png)


### void yazdir() fonksiyonu: 

Fonksiyonumuzda bağlı listede bulunan düğümlerin elemanları olan adet ve S_kelime sırasıyla yazdırılır.

![image](https://user-images.githubusercontent.com/58952369/180409330-30823e70-1404-4a09-af07-315db2e1524e.png)

# Genel Yapı

Projemizde başlangıç olarak metin dosyası içinde bulunan metin alınır. Metin malloc fonksiyonu ile bellekte ayırdığımız alan içerisine yerleştirilir. Sonrasında metnin içerisinde düzenlemeler yapılır. Oluşturduğumuz yeni metin belgesine bu metin yerleştirilir ve yeni oluşan metin bellekteki ayırdığımız alana atılır. Sonrasında metindeki kelimeler teker teker ayrılarak ekle fonksiyonuna gönderilir. İlk olarak kelimenin tekrar sayısına ve bağlı listede bulunma durumuna bakılır. Bu kıyaslamalar yapıldıktan sonra kelimenin adet sayısına göre basaEkle , sonaEkle ve arayaEkle fonksiyonları ile kelimeler bağlı listeye eklenir. Ekleme işlemi bittikten sonra yazdır fonksiyonu yardımıyla kelimeler ekrana yazdırılır.

# KAYNAKÇA

https://www.youtube.com/watch?v=lTFmKiyo0nU&list=PLUUSh8du1azZEsdngPxMQGLnatId0V4h9 

http://edestek2.kocaeli.edu.tr/course/view.php?id=50

https://stackoverflow.com/ 

https://github.com/ 

https://www.geeksforgeeks.org/
