// qingke.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "青柯坪");
	set("long", @LONG
走过崎岖的十八盘，穿过云门，就到了青柯坪。青柯坪是一山间盆
地，地势略为平坦。从这里开始，上山的路都是由原地凿出的石阶。远
远望见一个小小石亭，便是赌棋亭了。相传宋太祖与华夷先生曾弈棋于
此，将华山作为赌注，宋太祖输了，从此华山上的土地就不须缴纳钱粮。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"eastup"    : __DIR__"huixinshi",
		"northdown" : __DIR__"yunmen",
	]));
	set("objects",([ 
		__DIR__"npc/tao-jun" : 1,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -910);
	set("coor/y", 240);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
 
