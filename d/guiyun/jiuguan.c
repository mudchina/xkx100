// Room: /d/guiyun/jiuguan.c
// Last Modified by winder on Jul. 9 2001

#define KICK_TO	__DIR__"road2"

inherit ROOM;

int do_sit(string arg);
int do_stand();
int do_order(string arg);
int do_eat(string arg);
int do_drink(string arg);
int do_pay();
int do_buy();
int do_quit();
string look_sign();
string look_table();
void quarter_pass();

mapping *food = ({
([	"name" : "油条",
	"unit" : "根",
	"short" : "youtiao",
	"value" : 10,
	"time" : "早",
	"remaining" : 1,
	"supply" : 30
]),
([	"name" : "小笼包",
	"unit" : "盘",
	"short" : "baozi",
	"value" : 20,
	"time" : "早",
	"remaining" : 2,
	"supply" : 30
]),
([	"name" : "米饭",
	"unit" : "碗",
	"short" : "mifan",
	"value" : 40,
	"time" : "午",
	"remaining" : 4,
	"supply" : 30
]),
([	"name" : "鱼香肉丝",
	"unit" : "盘",
	"short" : "rousi",
	"value" : 120,
	"time" : "午",
	"remaining" : 6,
	"supply" : 50
]),
([	"name" : "清蒸鲤鱼",
	"unit" : "盘",
	"short" : "liyu",
	"value" : 200,
	"time" : "午",
	"remaining" : 9,
	"supply" : 50
]),
([	"name" : "米饭",
	"unit" : "碗",
	"short" : "mifan",
	"value" : 40,
	"time" : "晚",
	"remaining" : 4,
	"supply" : 30
]),
([	"name" : "鱼香肉丝",
	"unit" : "盘",
	"short" : "rousi",
	"value" : 120,
	"time" : "晚",
	"remaining" : 6,
	"supply" : 50
]),
([	"name" : "清蒸鲤鱼",
	"unit" : "盘",
	"short" : "liyu",
	"value" : 200,
	"time" : "晚",
	"remaining" : 9,
	"supply" : 50
]),
([	"name" : "东坡肘子",
	"unit" : "盘",
	"short" : "zhouzi",
	"value" : 250,
	"time" : "晚",
	"remaining" : 8,
	"supply" : 60
])
});

mapping *liquid = ({
([	"name" : "面汤",
	"unit" : "碗",
	"short" : "miantang",
	"value" : 10,
	"time" : "早",
	"remaining" : 2,
	"supply" : 12
]),
([	"name" : "稀粥",
	"unit" : "碗",
	"short" : "xizhou",
	"value" : 16,
	"time" : "早",
	"remaining" : 2,
	"supply" : 18
]),
([	"name" : "稀粥",
	"unit" : "碗",
	"short" : "xizhou",
	"value" : 16,
	"time" : "午",
	"remaining" : 2,
	"supply" : 18
]),
([	"name" : "米酒",
	"unit" : "坛",
	"short" : "mijiu",
	"value" : 130,
	"time" : "午",
	"remaining" : 9,
	"supply" : 40
]),
([	"name" : "三鲜汤",
	"unit" : "碗",
	"short" : "sanxiantang",
	"value" : 70,
	"time" : "午",
	"remaining" : 8,
	"supply" : 24
]),
([	"name" : "稀粥",
	"unit" : "碗",
	"short" : "xizhou",
	"value" : 16,
	"time" : "晚",
	"remaining" : 2,
	"supply" : 18
]),
([	"name" : "米酒",
	"unit" : "坛",
	"short" : "mijiu",
	"value" : 130,
	"time" : "晚",
	"remaining" : 9,
	"supply" : 40
]),
([	"name" : "三鲜汤",
	"unit" : "碗",
	"short" : "sanxiantang",
	"value" : 70,
	"time" : "晚",
	"remaining" : 8,
	"supply" : 24
]),
([	"name" : "冬瓜海螺汤",
	"unit" : "碗",
	"short" : "hailuotang",
	"value" : 90,
	"time" : "晚",
	"remaining" : 8,
	"supply" : 28
])
});

void create()
{
	set("short", "小酒馆");
	set("long", @LONG
这是太湖边的一家小酒馆。你一走进来，就闻到一股酒菜的香味，
勾人食涎。厅内摆着几张八仙桌(table)， 桌上整齐地摆放着碗筷，四
周放着些椅子(chair)。 一个酒保正在忙个不停。你要想打听江湖掌故
和谣言，这里是个好所在。柜台上立着一个价目表(sign)。
LONG
	);

	set("exits", ([
		"north" : KICK_TO,
	]));

	set("item_desc", ([
		"sign" : (: look_sign :),
		"table" : (: look_table :),
		"chair" : "木制的坐椅，看起来好象很结实。\n",
	]) );

	set("objects",([
		__DIR__"npc/zhanggui" : 1,
		__DIR__"npc/jiubao" : 1,
	]) ); 

	setup();
	quarter_pass();
}

void init()
{
	add_action("do_quit", "quit");
	add_action("do_buy", "buy");
	add_action("do_pay", "pay");
	add_action("do_pay", "jiezhang");
	add_action("do_eat", "eat");
	add_action("do_eat", "chi");
	add_action("do_drink", "drink");
	add_action("do_drink", "he");
	add_action("do_order", "order");
	add_action("do_order", "dian");
	add_action("do_stand", "stand");
	add_action("do_stand", "zhan");
	add_action("do_sit", "sit");
	add_action("do_sit", "zuo");
}

void kick_all()
{
	object *ob;
	int i, pay;

	set_temp("serve", "无");
	tell_room(this_object(), "酒保大喊了一声：“打烊啦！”\n", ({}));
	ob = all_inventory(this_object());
	for(i = 0; i < sizeof(ob); i++)
	{
		if (userp(ob[i]))
		{
			if (pay = ob[i]->query_temp("total_pay"))
			{
				message_vision("酒保对$N喝道：“付帐走人！”\n", ob[i]);
				if (!ob[i]->query_temp("to_pay"))
				{
					message_vision("酒保把$N从座位上拽了起来，拉到柜台前。\n", ob[i]);
					message_vision("掌柜翻出菜单，拨打了一阵算盘后告诉$N：“一共" + chinese_number(pay) + "文钱。”\n", ob[i]);
					ob[i]->delete_temp("marks/sit");
					ob[i]->set_temp("to_pay", 1);
				}
			}
			else
			{
				if (!living(ob[i])) message_vision("酒保把$N扔出了酒店。\n", ob[i]);
				else message_vision("酒保把$N推出了酒店。\n", ob[i]);
				ob[i]->delete_temp("marks/sit");
				ob[i]->delete_temp("cai_count");
				ob[i]->delete_temp("cai_1");
				ob[i]->delete_temp("cai_2");
				ob[i]->delete_temp("cai_3");
				ob[i]->delete_temp("cai_4");
				ob[i]->delete_temp("cai_5");
				ob[i]->move(KICK_TO);
				if (!living(ob[i])) tell_room(KICK_TO, ob[i]->name() + "被扔出了酒店。\n", ({ob[i]}));
				else tell_room(KICK_TO, ob[i]->name() + "被推出了酒店。\n", ({ob[i]}));
			}
		}
	}
}

void quarter_pass()
{
//	mixed *local;
	object *ob;
	int i, paytime;
	string time = NATURE_D->game_time();
/*  时间被修整
	local = localtime(time() * 60);
	if (local[2] < 6) kick_all();
	else if (local[2] < 9) set_temp("serve", "早");
	else if (local[2] < 11) set_temp("serve", "无");
	else if (local[2] < 14) set_temp("serve", "午");
	else if (local[2] < 17) set_temp("serve", "无");
	else if (local[2] < 21) set_temp("serve", "晚");
	else kick_all();
*/
	if( strsrch(time, "卯时") >= 0) set_temp("serve", "早");
	else if( strsrch(time, "辰时") >= 0) set_temp("serve", "早");
	else if( strsrch(time, "巳时") >= 0) set_temp("serve", "无");
	else if( strsrch(time, "午时") >= 0) set_temp("serve", "午");
	else if( strsrch(time, "未时") >= 0) set_temp("serve", "无");
	else if( strsrch(time, "申时") >= 0) set_temp("serve", "晚");
	else if( strsrch(time, "酉时") >= 0) set_temp("serve", "晚");
	else kick_all();

	ob = all_inventory(this_object());
	for(i = 0; i < sizeof(ob); i++)
	{
		if (paytime = ob[i]->query_temp("to_pay"))
		{
			paytime++;
			if (paytime == 6 && ob[i]->query_temp("total_pay")) {
				message_vision("酒保对$N大喝一声：“怎么还不付帐？！想吃霸王餐啊！”\n", ob[i]);
				message_vision("酒保叫来几个大汉，指着$N说：“给我打！”\n", ob[i]);
				message_vision("大汉们围住$N，乱拳齐下。\n", ob[i]);
				ob[i]->delete_temp("total_pay");
				ob[i]->delete_temp("to_pay");
				ob[i]->delete_temp("cai_count");
				ob[i]->delete_temp("cai_1");
				ob[i]->delete_temp("cai_2");
				ob[i]->delete_temp("cai_3");
				ob[i]->delete_temp("cai_4");
				ob[i]->delete_temp("cai_5");
				ob[i]->unconcious();
				message_vision("酒保撇撇嘴，说：“丢出去！”\n", ob[i]);
				message_vision("大汉们抬起$N，扔出了店门。\n", ob[i]);
				ob[i]->move(KICK_TO);
				tell_room(KICK_TO, "只见酒馆大门一开，几个大汉将一个昏迷不醒的家伙丢了出来。\n", ({ob[i]}));
			}
			else ob[i]->set_temp("to_pay", paytime);
		}
	}
	call_out("quarter_pass", 30);
}

int do_sit(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if (arg == "table" || arg == "zhuozi")
		return notify_fail("你要坐在桌子上？那先把你煮熟了再端上来吧。\n");	
	if ( !arg || (arg != "chair" && arg != "yizi") )
		return notify_fail("你要坐在地板上？有个性！不过这样的话恐怕你会被轰出酒馆了。\n");	
	if (me->query_temp("marks/sit"))
		return notify_fail("你已经坐在座位上了。\n");	
	if (me->query_temp("total_pay"))
		return notify_fail("先把旧帐结清了！\n");	
	remove_call_out("check_payed");
	message_vision("$N找了个空位座下，准备吃饭。\n", me);	
	if (query_temp("serve") == "无")
	{
		message_vision("酒保走过来对$N说：“对不起您哪，现在不是用餐时间。”\n", me);	
		message_vision("$N无奈地又站了起来。\n", me);	
		return 1;
	}
	me->set_temp("marks/sit", 1);
	return 1;
}

int do_stand()
{
	object me = this_player();

	if (!me->query_temp("marks/sit"))
		return notify_fail("你已经站着了，是不是站久了有点发昏啊？\n");	
	if (me->query_temp("total_pay"))
		return notify_fail("没付钱(pay)就想走吗？\n");	
	message_vision("$N拍拍屁股，站了起来。\n", me);	
	me->delete_temp("marks/sit");
	return 1;
}

int do_order(string arg)
{
	object me = this_player();
	string serve;
	int i, count;

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if (!me->query_temp("marks/sit"))
		return notify_fail("酒保用好象瞧见一个怪物一样的眼神打量着你：“站着吃喝？有位子不坐，您不嫌累呀？”\n");
	if (!arg)
		return notify_fail("酒保不耐烦地说：“你究竟要什么啊？”\n");
			
	serve = query_temp("serve");
	if (serve == "无")
		return notify_fail("酒保赔笑道：“客官见谅，厨房已经停火了！”\n");
	if (!me->query_temp("total_pay")) me->set_temp("total_pay", 0);
	if (!(count = me->query_temp("cai_count")))
		me->set_temp("cai_count", 0);
	for (i = 0; i < sizeof(food); i++)
		if ((arg == food[i]["name"] || arg == food[i]["short"]) &&
			serve == food[i]["time"])
		{
			message_vision("$N冲酒保喊道：“来" + food[i]["unit"] + food[i]["name"] +"。”\n", me);
			if (me->query_temp("cai_count") >= 5)
			{
				message_vision("酒保奇怪地问$N：“您打算开宴呀？！先把桌上的吃完了再说！”\n", me);
				return notify_fail("");
			}
			message_vision("酒保喊着：“来～啦～”，给$N端来了" + food[i]["unit"] + food[i]["name"] +"。\n", me);
			me->add_temp("total_pay", food[i]["value"]);
			me->add_temp("cai_count", 1);
			me->set_temp("cai_"+count+"/name", food[i]["name"]);
			me->set_temp("cai_"+count+"/short", food[i]["short"]);
			me->set_temp("cai_"+count+"/unit", food[i]["unit"]);
			me->set_temp("cai_"+count+"/remaining", food[i]["remaining"]);
			me->set_temp("cai_"+count+"/supply", food[i]["supply"]);
			me->set_temp("cai_"+count+"/type", "food");
			return 1;
		}
	for (i = 0; i < sizeof(liquid); i++)
		if ((arg == liquid[i]["name"] ||
			arg == liquid[i]["short"]) &&
			serve == liquid[i]["time"])
		{
			message_vision("$N冲酒保喊道：“来" + liquid[i]["unit"] + liquid[i]["name"] +"。”\n", me);
			if (me->query_temp("cai_count") >= 5)
			{
				message_vision("酒保奇怪地问$N：“您打算开宴呀？！先把桌上的吃完了再说！”\n", me);
				return notify_fail("");
			}
			message_vision("酒保喊着：“来～啦～”，给$N端来了" + liquid[i]["unit"] + liquid[i]["name"] +"。\n", me);
			me->add_temp("total_pay", liquid[i]["value"]);
			me->add_temp("cai_count", 1);
			me->set_temp("cai_"+count+"/name", liquid[i]["name"]);
			me->set_temp("cai_"+count+"/short", liquid[i]["short"]);
			me->set_temp("cai_"+count+"/unit", liquid[i]["unit"]);
			me->set_temp("cai_"+count+"/remaining", liquid[i]["remaining"]);
			me->set_temp("cai_"+count+"/supply", liquid[i]["supply"]);
			me->set_temp("cai_"+count+"/type", "liquid");
			return 1;
		}
	return notify_fail("酒保不耐烦地说：“没这样菜！”\n");
}

int do_eat(string arg)
{
	object me = this_player();
	int i, count, remaining;

	if (!arg) return 0;
			
	if (!(count = me->query_temp("cai_count"))) return 0;
	for (i = 0; i < count; i++)
		if (me->query_temp("cai_" + i + "/type") == "food" &&
			(arg == me->query_temp("cai_" + i + "/name") ||
			arg == me->query_temp("cai_" + i + "/short")))
			break;
	if (i == count) return 0;
	if (!me->query_temp("marks/sit"))
	{
		write( "酒保用好象瞧见一个怪物一样的眼神打量着你：“站着吃喝？有位子不坐，您不嫌累呀？”\n");
		return 1;
	}
	if (me->is_busy()) {
		write("你上一个动作还没有完成。\n");
		return 1;
	}
	if (me->query("food") >= me->max_food_capacity())
	{
		write("你已经吃太饱了，再也塞不下任何东西了。\n");
		return 1;
	}

	me->add("food", me->query_temp("cai_" + i + "/supply"));
	if (me->is_fighting()) me->start_busy(2);

	message_vision("$N端起一" + me->query_temp("cai_" + i + "/unit") + me->query_temp("cai_" + i + "/name") +"，吃了两口。\n", me);
	remaining = me->query_temp("cai_" + i + "/remaining");
	remaining--;
	if (remaining == 0)
	{
		message_vision("$N将一" + me->query_temp("cai_" + i + "/unit") + me->query_temp("cai_" + i + "/name") +"吃得一干二净。\n", me);
		for (; i < count - 1; i++)
		{
			me->set_temp("cai_" + i + "/name", me->query_temp("cai_" + (i + 1) + "/name"));
			me->set_temp("cai_" + i + "/short", me->query_temp("cai_" + (i + 1) + "/short"));
			me->set_temp("cai_" + i + "/unit", me->query_temp("cai_" + (i + 1) + "/unit"));
			me->set_temp("cai_" + i + "/remaining", me->query_temp("cai_" + (i + 1) + "/remaining"));
			me->set_temp("cai_" + i + "/supply", me->query_temp("cai_" + (i + 1) + "/supply"));
			me->set_temp("cai_" + i + "/type", me->query_temp("cai_" + (i + 1) + "/type"));
		}
		me->add_temp("cai_count", -1);	
	}
	else
		me->set_temp("cai_" + i + "/remaining", remaining);
	return 1;
}

int do_drink(string arg)
{
	object me = this_player();
	int i, count, remaining;

	if (!arg) return 0;
			
	if (!(count = me->query_temp("cai_count"))) return 0;
	for (i = 0; i < count; i++)
		if (me->query_temp("cai_" + i + "/type") == "liquid" &&
			(arg == me->query_temp("cai_" + i + "/name") ||
			arg == me->query_temp("cai_" + i + "/short")))
			break;
	if (i == count) return 0;
	if (!me->query_temp("marks/sit"))
	{
		write( "酒保用好象瞧见一个怪物一样的眼神打量着你：“站着吃喝？有位子不坐，您不嫌累呀？”\n");
		return 1;
	}
	if (me->is_busy())
	{
		write("你上一个动作还没有完成。\n");
		return 1;
	}
	if (me->query("water") >= me->max_water_capacity())
	{
		write("你已经喝太饱了，再也灌不下任何东西了。\n");
		return 1;
	}

	me->add("water", me->query_temp("cai_" + i + "/supply"));
	if (me->is_fighting()) me->start_busy(2);

	message_vision("$N端起一" + me->query_temp("cai_" + i + "/unit") + me->query_temp("cai_" + i + "/name") +"，喝了两口。\n", me);
	remaining = me->query_temp("cai_" + i + "/remaining");
	remaining--;
	if (remaining == 0)
	{
		message_vision("$N将一" + me->query_temp("cai_" + i + "/unit") + me->query_temp("cai_" + i + "/name") +"喝得一干二净。\n", me);
		for (; i < count - 1; i++)
		{
			me->set_temp("cai_" + i + "/name", me->query_temp("cai_" + (i + 1) + "/name"));
			me->set_temp("cai_" + i + "/short", me->query_temp("cai_" + (i + 1) + "/short"));
			me->set_temp("cai_" + i + "/unit", me->query_temp("cai_" + (i + 1) + "/unit"));
			me->set_temp("cai_" + i + "/remaining", me->query_temp("cai_" + (i + 1) + "/remaining"));
			me->set_temp("cai_" + i + "/supply", me->query_temp("cai_" + (i + 1) + "/supply"));
			me->set_temp("cai_" + i + "/type", me->query_temp("cai_" + (i + 1) + "/type"));
		}
		me->add_temp("cai_count", -1);	
	}
	else me->set_temp("cai_" + i + "/remaining", remaining);
	return 1;
}

int do_pay()
{
	object me = this_player();
	int pay;

	if (!(pay = me->query_temp("total_pay")))		
		return notify_fail("掌柜赔笑道：“您是来做善事是吗？不吃也付帐？”\n");
	if (me->query_temp("marks/sit"))
	{
		message_vision("$N站起身来，走到柜台前结帐。\n", me);
		message_vision("掌柜翻出菜单，拨打了一阵算盘后告诉$N：“一共" + MONEY_D->price_str(pay) + "。”\n", me);
		message_vision("掌柜冲着酒保嚷道：把这位客官桌子上的剩菜收拾干净。\n", me);
	}
	else
	{
		message_vision("$N向掌柜问道：“还差多少？”\n", me);
		message_vision("掌柜翻了翻白眼，说道：“还差" + MONEY_D->price_str(pay) + "。”\n", me);
	}
	me->delete_temp("marks/sit");
	me->delete_temp("cai_count");
	me->set_temp("to_pay", 1);
	return 1;
}

int do_buy()
{
	write("酒保说道：“本店不外卖，请坐下来(sit)点菜(order)。”\n");
	return 1;
}

int do_quit()
{
	if (this_player()->query_temp("total_pay"))
	{
		write("吃饱喝足了不付钱就想退出？！\n");
		return 1;
	}
	return 0;
}

string look_sign()
{
	string serve;
	int i;

	write("牌子上写着：\n");
	serve = query_temp("serve");
	if (serve == "无")
	{
		write("    非用餐时间。\n");
		return "";
	}
	write("    " + serve + "餐供应以下饭食，随便您点(order)：\n");
	for (i = 0; i < sizeof(food); i++)
		if (serve == food[i]["time"]) 
			printf("    %30s    每%s文。\n", food[i]["name"] + "(" + food[i]["short"] + ")", food[i]["unit"] + chinese_number(food[i]["value"]));
	for (i = 0; i < sizeof(liquid); i++)
		if (serve == liquid[i]["time"]) 
			printf("    %30s    每%s文。\n", liquid[i]["name"] + "(" + liquid[i]["short"] + ")", liquid[i]["unit"] + chinese_number(liquid[i]["value"]));
	return "";
}

string look_table()
{
	object me = this_player();
	int i, j, num, count;
	string name;

	if (!(count = me->query_temp("cai_count")))
	{
		write("桌子上是空的。\n");
		return "";
	}
	write("你面前的桌子上放着：\n");
	for (i = 0; i < count; i++)
	{
		name = me->query_temp("cai_" + i + "/name");
		num = 1;
		for (j = 0; j < count; j++)
		{
			if (j == i) continue;
			if (name == me->query_temp("cai_" + j + "/name"))
			{
				if (j < i)
				{
					num = 0;
					break;
				}
				num++;
			}
		}
		if (!num) continue;
		write("    " + chinese_number(num) + me->query_temp("cai_" + i + "/unit") + name + "(" + me->query_temp("cai_" + i + "/short") +")。\n");
	}
	return "";
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("marks/sit"))
		return notify_fail("你打算连椅子也搬出去？\n");	
	if (me->query_temp("total_pay"))
		return notify_fail("酒保拦住你说：“不付钱就想溜？找扁啊！”\n");	
	me->delete_temp("cai_count");
	me->delete_temp("cai_1");
	me->delete_temp("cai_2");
	me->delete_temp("cai_3");
	me->delete_temp("cai_4");
	me->delete_temp("cai_5");
	return ::valid_leave(me, dir);
}
