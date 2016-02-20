inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的、行商
的、赶着大车的马夫、上京赶考的书生，熙熙攘攘，非常热闹。不时还
有两三骑快马从身边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的
杨树林。从这里远远的就可以望见北京城。西南是通往恒山。
LONG );
	set("exits", ([
		"northwest" : __DIR__"road5",
		"southeast" : __DIR__"road7",
		"southwest" : "/d/hengshan/jinlongxia",
	]));
	set("no_clean_up", 0);
 	set("outdoors", "huabei");
	set("coor/x", -10);
	set("coor/y", 3210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

