// Room: /d/nanshaolin/gulou7.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鼓楼七层");
	set("long", @LONG
这里就是鼓楼之顶。直入眼帘的便是一只大鼓。大鼓鼓身通红，似
由白杨木箍成。两头包以水牛皮，用一匝大铜钉钉在鼓身边缘。鼓心有
一圈白渍，看来是因为多次击打形成的。整个大鼓放在一个一人高的架
子上，架子底层搁着两根大鼓槌。
LONG );
	set("exits", ([
		"down" : __DIR__"gulou6",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1800);
	set("coor/y", -6280);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
