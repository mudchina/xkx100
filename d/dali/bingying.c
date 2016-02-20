//Room: /d/dali/bingying.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","兵营");
	set("long",@LONG
大理国虽小，却重视精兵良将。然屈人必先屈志，兵戈乃下下之
策，段氏大理先与北邻宋朝修和，再以姻亲拉拢当地人，多年无战事。
这是城里的铁骑营，为皇族的嫡系，装备给养无不优于中原地方。军
士们严阵以待，盔甲鲜明，刀剑锋利。
LONG);
	set("objects", ([
	   __DIR__"npc/bing": 2,
	   __DIR__"npc/weishi1": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"dahejiewest",
	    "west"   : __DIR__"majiu",
	]));
	set("coor/x", -41000);
	set("coor/y", -71040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}