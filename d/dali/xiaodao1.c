//Room: /d/dali/xiaodao.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","林荫小道");
	set("long",@LONG
沿林荫小道曲折前行约四十公尺，只见古树林立，浓荫蔽天，一方清
泉嵌于其间，底铺青石，泉水明澈，常有人掷钱币于池中，观其缓缓旋落，
阳光从树顶筛下，池底银光闪烁，倍感泉水清冽。池边距地面约二三尺的
地方有一粗可合抱的树干，伸过泉上，池旁建有小亭，小坐生凉，十分清
幽。 
LONG);
	set("objects", ([
	   __DIR__"npc/maque": 1,
	]));
	set("outdoors", "dalic");
	set("exits",([ /* sizeof() == 1 */
	    "northup"  : __DIR__"qingxi",
	    "south"    : __DIR__"heilongling",
	    "west"     : __DIR__"hudiequan",
	]));
	set("coor/x", -38000);
	set("coor/y", -69000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}