//Room: /d/dali/yaopu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","药铺");
	set("long",@LONG
这是一家神秘的药铺，座落在大和街和市中心的交界处，普通的
门面和招牌，街坊们都说这家药铺的药灵验的很。从药柜上的几百个
小抽屉里散发出来的一股浓浓的药味，让你几欲窒息。据说这家店铺
有一种很神秘的药物。
LONG);
	set("objects", ([
//	   __DIR__"npc/hehongyao": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"taiheeast",
	]));
	set("coor/x", -39990);
	set("coor/y", -71020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}