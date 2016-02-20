//Room: /d/foshan/beidimiao.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","北帝庙");
	set("long",@LONG
北帝庙坐北朝南。院子中一个大水塘，塘中石龟石蛇，昂然盘
踞。大殿神像石板上血迹殷然。北帝神像立于大殿正中。
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"street1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1600);
	set("coor/y", -6500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
