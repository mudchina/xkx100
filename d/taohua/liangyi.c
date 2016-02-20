// Room: /d/taohua/liangyi.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "两仪");
	set("long", @LONG
这里是两仪层，你一走下来，往上的铁梯就被撤掉了。往下有一道
悬挂着的铁梯，通向四象层。所谓两仪，系指阴阳，是世界的二端。虽
然太极浑圆，仍由对立着又统一的二极构成。阴阳之间不停转化，生生
不息，是世界运行的原动力。然而阴阳之间仍然不是绝对的对立，所谓
阴中有阳，阳中含阴。是故少阳伴太阴而少阴伴太阳，此两仪生四象。
以八干四维而论，艮居于东北而为鬼门，谓之阴，坤生于西南而为人门，
谓之阳。
LONG
	);
	set("exits", ([ 
		"northeast" : __DIR__"yin",
		"southwest" : __DIR__"yang",
		"down" : __DIR__"sixiang",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8520);
	set("coor/y", -4680);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_save", "save");
	add_action("do_quit", "quit");
}

int do_save()
{
	write("这里不准存盘！\n");
	return 1;
}

int do_quit()
{
	write("这里不准退出！\n");
	return 1;
}