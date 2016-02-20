// Room: /d/lingxiao/wave2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","冰洞");
	set("long",@LONG 
这里又是一个冰洞，但从这里往上望，居然可以透过冰壁看到外面
的万里群山。原来这外面的墙壁是悬崖上的冰层，月光射进冰洞，照得
满洞生辉，银光闪闪，让人想起“冰簟银床梦不成，碧天如水夜云轻”
的意境。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"enter" : __DIR__"wave", 
		"east"  : __DIR__"wave1", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -31020);
	set("coor/y", -8950);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}

