// yuquan.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "玉泉院");
	set("long", @LONG
这里因屋后的玉泉而得名，是宋代陈希夷隐居的地方。周围生着十
二株大龙藤，夭矫多姿，枝干中空，就如飞龙相似，相传是希夷先生陈
抟老祖所植。院内绿荫蔽日，泉石如画，流水萦回，回廊曲折。院中有
清泉一股，泉水甘冽，传与山顶镇岳宫玉井相通，故名玉泉，玉泉院因
此得名。
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"path1",
	]));
	set("objects", ([
		__DIR__"npc/teller": 1
	]) );
	set("outdoors", "huashan");

	set("coor/x", -920);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
 
