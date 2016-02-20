//room: /d/mingjiao/neishi.c
inherit ROOM;

void init();
void create()
{
	set("short","明教内室");
	set("long", @LONG
这里是明教内室。小小桌前的窗外，望出去是连绵万里的巍巍昆仑。
窗棂门扇均雕制得美仑美奂，精巧异常桌前端坐一个亮丽女孩，你乍一
见惊异她的美貌，不禁轻轻叫出声来。
LONG );
	set("exits",([
		"out" : __DIR__"dadian",
	]));
	set("no_fight","1");
	set("no_beg","1");
	set("objects",([
		CLASS_D("mingjiao")+"/xiaozhao":1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 1080);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}