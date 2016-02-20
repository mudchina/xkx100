// Room: /d/suzhou/sdhyuan.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "花园");
	set("long",@long
这里原是吴宫的御花园遗址，园内有夫差与西施采莲取乐，称为“
山顶荡舟”的玩花池。池的东面挖了吴王井，专供西施照容晓妆之用。
西面有一口梁代高僧修浚的智积井，寺内和尚引水常取与此。
long);
	set("outdoors", "suzhou");
	set("exits",([
		"west"     : __DIR__"zhijijing",
		"east"     : __DIR__"wuwangjing",
		"eastdown" : __DIR__"lingyanta",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
