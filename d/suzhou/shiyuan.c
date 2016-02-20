// Room: /d/suzhou/shiyuan.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
        set("short", "石鼋");
        set("long",@long
这是一块突出平地的巨石，称为“石鼋”。石鼋背面刻着“望佛来
”三个字，背上凹痕处，传说是夫差与西施立石昂首眺望太湖石留下的
脚印。从石鼋旁俯视，左右有两个水洼。
long);
	set("outdoors", "suzhou");
	set("objects",([
		__DIR__"npc/ke" : 2,
	]));
	set("exits",([
		"southup" : __DIR__"lingyansi",
		"westdown" : __DIR__"shuiwa1",
		"eastdown" : __DIR__"shuiwa",
		"northdown" : __DIR__"yingxiaoting",
		"southwest" : __DIR__"mubei",
	]));
	set("coor/x", 900);
	set("coor/y", -1110);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
