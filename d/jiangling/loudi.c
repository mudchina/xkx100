//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "楼底");
	set ("long", @LONG
一座两层小楼，四周有低矮的围墙，墙内种了几株柳树。二楼的窗
槛上放了一盆黄色蔷薇，只是三朵花儿都已萎谢，一阵风吹过，凋零的
花瓣便散落飘飞，忽而一对燕子吱哑飞过，感觉真有说不出的凄凉。小
门内光线昏暗，但仍看得见屋角有窄小的楼梯。
LONG);

	set("exits", ([ 
		"up"   : __DIR__"loudao",
		"west" : __DIR__"feiyuan",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1460);
	set("coor/y", -2039);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
