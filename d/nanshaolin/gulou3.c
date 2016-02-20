// Room: /d/nanshaolin/gulou3.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鼓楼三层");
	set("long", @LONG
塔身往上似乎越来越窄，楼梯也渐为挤仄。扶手上不少朽坏处续接
了新木，漆色也是新旧不同。从窗孔往外望，往北可以看到竹林中的藏
经楼和方丈楼露出飞檐一角，往东则是前殿的屋顶，屋脊上塑了个大大
的“佛”字。
LONG );
	set("exits", ([
		"up"   : __DIR__"gulou4",
		"down" : __DIR__"gulou2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6280);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

