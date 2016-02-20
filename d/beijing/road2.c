inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的、行商
的、赶着大车的马夫、上京赶考的书生，熙熙攘攘，非常热闹。不时还
有两三骑快马从身边飞驰而过，扬起一路尘埃。马上的人个个身着劲装，
衣甲鲜明，有的还随身佩带着刀剑，看来都是些习武的江湖人。道路两
旁是整整齐齐的杨树林。
LONG );
	set("exits", ([
		"northwest" : __DIR__"road1",
		"southeast" : __DIR__"road3",
	]));
	set("objects",([
		"/d/taishan/npc/tangzi" : 2,
	]));
	set("outdoors", "huabei");
	set("coor/x", -150);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

