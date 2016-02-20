// Room: /d/qilian/loulan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "楼兰废墟");
	set("long", @LONG
当年楼兰王倾国力五载，修得这座楼兰城。后来楼兰王停止向汉朝
进贡，武帝遣霍去病平之，历时三载有余，屠尽楼兰之民，这里就成了
一座死城。后过百余年，楼兰城就消失了。据传埋于沙下，不知是否属
实。
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"northeast" : __DIR__"jiuquan",
		"west"      : "/d/xingxiu/yueerquan",
	]));
	set("objects", ([
		"/d/xingxiu/npc/shachong" : 2,
	]));
	set("coor/x", -20300);
	set("coor/y", 200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}