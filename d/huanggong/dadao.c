// Room: /d/huanggong/dadao.c

inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
这是通往宫中的大道. 北边远远能望见先农坛. 西边有一片猎场, 
是皇家的上林囿. 每年皇上都会去狩猎. 平时就比较冷清, 倒是那些动
物们, 乐得个安闲.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 2 */
		 "west" : __DIR__"lie1",
		 "east" : __DIR__"humen",
	]));
	set("no_clean_up", 0);

	set("coor/x", -250);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}