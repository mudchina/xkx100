// Room: /d/nanshaolin/zhlou2.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "钟楼二层");
	set("long", @LONG
每个楼层上都铺设了结实的木楼板，八角形的墙身上则开了四扇大
窗。从窗孔看，墙体也是极为厚实。从这里往外眺望，可以看到围绕塔
周的小园以及北边的竹林，随风飘来阵阵竹叶的清香。
LONG );
	set("exits", ([
		"up"   : __DIR__"zhlou3",
		"down" : __DIR__"zhlou1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

