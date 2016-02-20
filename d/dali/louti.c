//Room: /d/dali/louti.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","楼梯");
	set("long",@LONG
这就是通往二楼“迎宾斋”的楼梯，楼梯高有五十余级，上面铺
了鲜红的毛毡，楼梯两侧站了一些素衣卫士，楼上则是贵宾休息的地
方。
LONG);
	set("objects", ([
	   __DIR__"npc/weishi": 3,
	   CLASS_D("dali")+"/gaoshengtai": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "up"      : __DIR__"zoulang1",
	    "south"   : __DIR__"dating",
	]));
	set("coor/x", -50000);
	set("coor/y", -75000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}