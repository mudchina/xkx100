// Room: /d/taohua/jicui.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "积翠亭");
	set("long", @LONG
竹林内有座竹枝搭成的凉亭，亭上横额在月光下看得分明，是“积
翠亭”三字，两旁悬着副对联(duilian) 。亭中放着竹台竹椅，全是多
年之物，用得润了，月光下现出淡淡黄光。竹亭之侧并肩生着两棵大松
树，枝干虬盘，只怕已是数百年的古树。苍松翠竹，清幽无比。
LONG
	);
	set("exits",([
		"north" : __DIR__"hetang",
		"east"  : __DIR__"kefang",
		"south" : __DIR__"caodi",
	]) );
	set("no_clean_up",0);
	set("outdoors","taohua");
	set("item_desc",([
		"duilian" : "
桃                   碧
花                   海
影                   潮
里                   生
飞                   按
神                   玉
剑                   箫\n
"
	]) );
	set("objects",([
		CLASS_D("taohua")+"/huang" : 1,
	]) ); 

	set("coor/x", 9010);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}