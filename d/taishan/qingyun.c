// Room: /d/taishan/qingyun.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "青云洞");
	set("long", @LONG
这里是青云洞。传阴雨天洞内生青烟，与白云洞之云相遇即雨遍天
下。俗称《春秋公羊传》所载“触石而出，肤寸而合，不崇朝而遍雨乎
天下者，唯泰山尔”，即指此地。 
LONG );
	set("exits", ([
		"westup" : __DIR__"xiangshan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 380);
	set("coor/y", 760);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}
