// Room: /d/tiezhang/zzfeng.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "中指峰");
	set("long", @LONG
这里就是铁掌山的最高峰——中指峰。由于山势太高，峰顶仍存有
大量的积雪，白雪皑皑，在阳光的照射下，泛起一片耀眼的银光。纵目
远眺，湘西几百里景色尽收眼底，泸溪，辰溪如两条玉带，从山下缓缓
流过。远处那条白色的亮线，就是湘西的大江——沅江。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"southdown" : __DIR__"shanlu9",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2040);
	set("coor/y", -1770);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
