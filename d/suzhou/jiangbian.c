// Room: /d/suzhou/jiangbian.c
// Last Modified by Winder on May. 15 2001

inherit ROOM;

void create()
{
        set("short", "江边");
        set("long",@long
这条江叫做曹娥江。相传汉和帝时，这里有一名巫者，名叫曹盱，
能婆娑乐神。五月五日，醉舞舟中，堕江而死。其女年十四岁，绕江啼
哭七昼夜，跳入波中。后五日，负父之尸浮于江面，里人葬之江边，故
名。
long);
	set("outdoors", "suzhou");
	set("exits",([
		"northeast" : __DIR__"tulu2",
		"south"     : __DIR__"caoebei",
	]));
	set("no_clean_up", 0);
	set("coor/x", 770);
	set("coor/y", -1040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
