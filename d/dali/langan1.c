//Room: /d/dali/langan1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","杆栏");
	set("long",@LONG
摆夷族大多依树积木以居其上，就是杆栏，在夷语里叫做榔盘。
其构造大致略似楼，侧面开门，有梯可上下，上阁如车盖状，中层住
人，这里是下层，一般为牛羊圈。
LONG);
	set("objects",([
	    __DIR__"npc/shanyang" : 2,
	]));
	set("outdoors", "dalie");
	set("exits",([ /* sizeof() == 1 */
	    "north"   : __DIR__"nongtian2",
	    "up"      : __DIR__"langan2",
	]));
	set("coor/x", -31000);
	set("coor/y", -70610);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}