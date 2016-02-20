// Room: /d/taohua/entrance.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "入口");
	set("long", @LONG
这里是高台的顶层，往下有一道悬挂着的铁梯，通向太极层。墙壁
上挂着一个大牌子，上书：“入阵者不得回头，凶险自负！”笔势凶猛，
似在惊吓来人。旁边有一个说明(shuoming)。
LONG
	);
	set("exits", ([ 
		"down" : __DIR__"taiji",
		"west" : __DIR__"hill2",
	]) );
	set("outdoors","taohua");
	set("item_desc", ([
		"shuoming" : "
入阵规则：
  以一月之日入两仪。此入为初次进该层，如行阴则入阴，既入，复行阳则无妨。下同。
  以一日之时入四象。需知五灵对应方位的五行。
  以一年之月入五行。已生而未旺入，生之象，需生。行被生则迷，克则伤，被克则休。
                    已旺而未死入，衰之象，需克。行被克则迷，生则伤，被生则休。
                    已死方入，死之象，皆惊伤休，殆矣！
"
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8520);
	set("coor/y", -4680);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}