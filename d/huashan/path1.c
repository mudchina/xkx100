// path1.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "华山脚下");
	set("long", @LONG
西岳华山，巍然耸立于陕西省华阴县城南。它北瞰黄河，南连秦岭，
五座山峰高低错落，各据一方，其间又有一段若断若续的山岭相连，疏
密有度，神韵天成，远远望去，状若巨朵青莲，外围诸峰如莲瓣，中间
三峰似莲蕊，因此山便因“花”得名，取名华山。又因其西临少华山，
故华山又称太华。它素有「奇峰天下第一山」之称，西面是小村。北是
玉泉院。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"west"      : "/d/village/eexit",
		"north"     : __DIR__"yuquan",
		"south"     : __DIR__"caishi",
		"southeast" : __DIR__"shaluo",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x", -920);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
 
