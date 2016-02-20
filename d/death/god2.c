// Room: god2

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"圣殿"NOR);
	set("long", HIC @LONG
你步入到圣殿中。圣殿里的空间显得格外的大，你抬起头来，竟看
不到顶，四排三十二根白柱向上伸去，也不知道有多高。仙雾缭绕中，
你隐约看见前面一个平台上有一把金椅，上面似乎坐着个沉思的老人，
可你却看不清他的面容，你想再走上前去，却有一股奇异的力量将你挡
了回来，这恐怕就是神的力量吧，那位老人应该就是天帝了吧。
　　在你和天帝中间，有一条长长的翡翠石道，两旁坐着许多仙子，或
歌或舞，原来那和祥悦耳的音乐就是她们演奏出来的……。在圣殿中，
你只觉得幸福和安详，天国原来就是这样的……可是，你却慢慢觉得这
里过于冷清，不由开始怀念起那喧嚣嘈杂的尘世来……
LONG
NOR   );
	set("no_clean_up", 0);
	setup();
}

void reset()
{
	::reset();
	set("exits", ([ /* sizeof() == 1 */
		"down"  : __DIR__"god1",
		"north" : "/d/wizard/wizard_jail",
	]));
}

int valid_leave(object me, string dir)
{
	switch(dir)
	{
		case "down":
			write(HIW"你想离开圣殿了吗？…\n\n"NOR);
			break;
		default:
			write(HIG"你不愿呆在这个与世无争的地方吗？……\n\n"NOR);
	}
	write(HIB"既然你仍然留念凡尘……那就去吧……\n\n\n\n"NOR);
	write(HIY"在一片烟雾中，你慢慢离开了圣殿，……\n\n\n\n"NOR);
	this_player()->add("shen", (int)this_player()->query("shen") / 9);
	return 1;
}
