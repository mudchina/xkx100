//Room: /d/dali/tianweijing.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","天威径");
	set("long",@LONG
此处据说是三国时蜀汉诸葛孔明第七次擒孟获之处，孟获曰：“
公，天威也，吾既降，南人不复反也。”，故此得名。这是一条贯通
南北的大路，南去十里是喜州城，北上约三十里可达大理城。
LONG);
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"road4",
	    "south"      : __DIR__"xizhou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -40000);
	set("coor/y", -77000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}