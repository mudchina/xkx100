// Room: /d/suzhou/canlangting.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "沧浪亭");
	set("long", @LONG
沧浪亭在苏州的北大街南侧，因为环境相对幽雅，使得男女老少都
喜爱在这里闲庭散步。在亭中放眼望去，四周一片碧绿的草坪，亭子翼
然于耸翠之中，飞檐凌空琵琶形牌科，布满檐口四周，亭上的额匾和石
柱上的楹联(lian)使人更加喜爱这里。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("item_desc", ([
		"lian" :
"清风明月本无价 近水远山皆有情\n",
	]));
	set("exits", ([
		"southeast" : __DIR__"dongdajie1",
		"southwest" : __DIR__"xidajie1",
		"north"     : __DIR__"beidajie1",
		"south"     : __DIR__"baodaiqiao",
	]));
	set("coor/x", 850);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
