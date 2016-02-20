// Last modified by winder 2002.11.11

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("庄家", ({ "zhuang jia", "zhuang", "jia" }));
	set("long", "一位赌场老手，正笑眯眯地看着你。\n请输入 ya 来获取帮助。\n");
	set("no_get", 1);
	set("age", 40);
	set("per", 20);
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	if (clonep()) call_out("casino", 1);
}

void init()
{
	object me = this_player();

	add_action("do_ya", "ya");
	if (wizardp(me)) add_action("zuobi", "zuobi");
}

string *point=({
	"│　　　│\n"
	"│　●　│\n"
	"│　　　│\n",
	"│　●　│\n"
	"│　　　│\n"
	"│　●　│\n",
	"│●　　│\n"
	"│　●　│\n"
	"│　　●│\n",
	"│●　●│\n"
	"│　　　│\n"
	"│●　●│\n",
	"│●　●│\n"
	"│　●　│\n"
	"│●　●│\n",
	"│●　●│\n"
	"│●　●│\n"
	"│●　●│\n"
});

varargs int gen_point(int j)
{
	int i = random(6);

	if (j > 0 && j < 7) i = j - 1;
	say("┌───┐\n"+point[i]+"└───┘\n");
	return i+1;
}

int in_bet = 0;
int tc1, tc2;
mapping t=([
	"tc": HIR"头彩"NOR,
	"dc": HIW"大彩"NOR,
	"sd": HIG"双对"NOR,
	"qx": HIY"七星"NOR,
	"dd": HIB"单对"NOR,
	"sx": HIC"散星"NOR,
	"kp": HIM"空盘"NOR
]);
mapping b=([
	"tc": 35,
	"dc": 17,
	"sd": 11,
	"qx": 5,
	"dd": 3,
	"sx": 2,
	"kp": 5
]);

int do_ya(string arg)
{
	object me = this_player();
	int mount;
	string type, money, uid;

	if (!arg || sscanf(arg, "%s %d %s", type, mount, money) != 3)
		return notify_fail(
"ya tc <数量> <coin|silver|gold> 押头彩(两数顺序及点数均正确)       一赔卅五\n"
"ya dc <数量> <coin|silver|gold> 押大彩(两数点数正确)               一赔十七\n"
"ya sd <数量> <coin|silver|gold> 押双对(两数相同且均为偶数)         一赔十一\n"
"ya kp <数量> <coin|silver|gold> 押空盘(两数不同且均为偶数)         一赔五\n"
"ya qx <数量> <coin|silver|gold> 押七星(两数之和为七)               一赔五\n"
"ya dd <数量> <coin|silver|gold> 押单对(两数均为奇数)               一赔三\n"
"ya sx <数量> <coin|silver|gold> 押散星(两数之和为三、五、九、十一) 一赔二\n"
"每盘按从上到下的顺序只出现一种点型(头彩和大彩可同时出现)，其他情况都算庄家赢。\n");
	if (undefinedp(t[type])) return notify_fail("您要押什么？\n");
	if (mount < 1) return notify_fail("你要押多少钱？\n");
	if (mount > 200000) return notify_fail("您押的数目太大了。\n");
	switch(money)
	{
		case "gold":   mount *= 100;
		case "silver": mount *= 100;
		case "coin":   break;
		default:
		return notify_fail("只能押黄金(gold)、白银(silver)和铜钱(coin)。\n");
	}
	if (mount > 100000) return notify_fail("您押的数目太大了。\n");
	if (mount > me->query("balance"))
		return notify_fail("您没有这么多存款。\n");
	if (mount % 10) return notify_fail("必须以十个铜钱为基数下注。\n");
	if (!in_bet) return notify_fail("赌局还没开始呢。\n");
	if (in_bet > 1) return notify_fail("赌局已经开始了，等下一轮吧。\n");
	uid = me->query("id");
	if (query("bet/"+uid+"/"+type))
		return notify_fail("您已经押过"+t[type]+"了。\n");
	me->add("balance", -mount);
	set("bet/"+uid+"/"+type, mount);
	message_vision("$N拿出"+MONEY_D->money_str(mount)+"的存款押在"+t[type]+"上。\n", me);
	add("total/tt", mount);
	add("total/"+type, mount+mount*b[type]);
	if (type == "dc") add("total/tc", mount+mount*b[type]);
	return 1;
}

int debug = 0;
int zb1 = 0;
int zb2 = 0;

int zuobi(string arg)
{
	if (!arg)
	{
		debug = 1 - debug;
		return 0;
	}
	sscanf(arg, "%d %d", zb1, zb2);
	return 1;
}

void casino()
{
	say(name()+"唱道：新开盘！预叫头彩！\n");
	say(name()+"将两枚玉骰往银盘中一撒。\n");
	tc1 = gen_point();
	tc2 = gen_point();
	say(name()+"唱道：头彩骰号是" HIW +chinese_number(tc1)+ NOR "、" HIW +chinese_number(tc2)+ NOR "！\n");
	say("接着"+name()+"麻利地将玉骰从银盘中收回：现在开盘押钱！\n");
	delete("bet");
	delete("total");
	set("total/tc", 0);
	set("total/dc", 0);
	set("total/sd", 0);
	set("total/kp", 0);
	set("total/qx", 0);
	set("total/dd", 0);
	set("total/sx", 0);
	in_bet = 1;
	call_out("wait_start", 8, 3);
}

void wait_start(int i)
{
	say(name()+"喊道：本盘头彩骰号是" HIW +chinese_number(tc1)+ NOR "、" HIW +chinese_number(tc2)+ NOR "，各位客倌快押(ya)啊！\n");
	if (debug) message("wiz:yuj", sprintf("%O\n", query("total")), environment());
	if (i--) call_out("wait_start", 8, i);
	else call_out("readystart", 2, 3);
}

void readystart(int i)
{
	if (debug) message("wiz:yuj", sprintf("%O\n", query("total")), environment());
	if (i--) call_out("readystart", 2, i);
	else call_out("start", 2);
}

void start()
{
	in_bet = 2;
	say(name()+"喊道：封盘停押！本盘头彩骰号是" HIW +chinese_number(tc1)+ NOR "、" HIW +chinese_number(tc2)+ NOR "！\n");
	say(name()+"将两枚玉骰扔进两个金盅，一手持一盅摇将起来。\n");
	call_out("kai1", 3);
}

int p1, p2;

void kai1()
{
	mapping total = query("total");
	int i = sizeof(total), j, k = 7;

	if (i && !(zb1+zb2))
	{
		string* key = keys(total);
		while (k--)
		{
			for (j = random(i); key[j]=="tt"; j = random(i));
			if (total[key[j]] < total["tt"]/5*4+random(total["tt"])) break;
		}
		if (k >= 0)
		{
			switch (key[j])
			{
				case "tc": zb1 = tc1; zb2 = tc2; break;
				case "dc":
					if (tc1 != tc2)
					{
						zb2 = tc1; zb1 = tc2;
					}
					break;
				case "sd":
					do {
						zb1 = zb2 = random(3)*2+2;
					} while (zb2 == tc1 || zb2 == tc2);
					break;
				case "kp":
					do {
						do {
							zb1 = random(3)*2+2;
							zb2 = random(3)*2+2;
						} while (zb1 == zb2);
					} while (zb2 == tc1 || zb2 == tc2);
					break;
				case "qx":
					do {
						do {
							zb1 = random(6)+1;
							zb2 = random(6)+1;
						} while (zb1+zb2 != 7);
					} while (zb2 == tc1 || zb2 == tc2);
					break;
				case "dd":
					do {
						zb1 = random(3)*2+1;
						zb2 = random(3)*2+1;
					} while (zb2 == tc1 || zb2 == tc2);
					break;
				case "sx":
					do {
						do {
							zb1 = random(6)+1;
							zb2 = random(6)+1;
						} while (zb1+zb2 == 7 || !((zb1+zb2)%2));
					} while (zb2 == tc1 || zb2 == tc2);
			}
		}
	}
	say(name()+"将左手的金盅倒扣在银盘上，玉骰滚了出来。\n");
	p1 = gen_point(zb1);
	zb1 = 0;
	call_out("kai2", 5);
}

void kai2()
{
	say(name()+"将右手的金盅倒扣在银盘上，玉骰滚了出来。\n");
	p2 = gen_point(zb2);
	zb2 = 0;
	call_out("kai", 2);
}

int tt = 0;
int cc = 0;

void kai()
{
	mapping bet = query("bet");
	string *uid;
	object me;
	int i = sizeof(bet), tc=0, dc=0, sd=0, qx=0, dd=0, sx=0, kp=0;
	int utc, udc, usd, uqx, udd, usx, ukp, total;

	say(name()+"叫道：" HIW +chinese_number(p1)+ NOR "、" HIW +chinese_number(p2)+ NOR "……");
	if ((p1 == tc1 && p2 == tc2))
	{
		say(t["tc"]+"、"+t["dc"]);
		tc = 1;
		dc = 1;
	}
	else
		if (p1 == tc2 && p2 == tc1)
		{
			say(t["dc"]);
			dc = 1;
		}
		else
			if (p1 == p2 && p1 % 2 == 0)
			{
				say(t["sd"]);
				sd = 1;
			}
			else
				if (p1 % 2 && p2 % 2)
				{
					say(t["dd"]);
					dd = 1;
				}
				else
					switch (p1+p2)
					{
						case 7:
							say(t["qx"]); qx = 1;
							break;
						case 3:
						case 5:
						case 9:
						case 11:
							say(t["sx"]); sx = 1;
							break;
						default:
							say(t["kp"]); kp = 1;
					}
	say("。\n");
	if (i)
	{
		uid = keys(bet);
		while (i--)
		{
			me = LOGIN_D->find_body(uid[i]);
// 不在房间的不给钱
			if (!me || !present(me, environment())) continue;
			utc = query("bet/"+uid[i]+"/tc");
			udc = query("bet/"+uid[i]+"/dc");
			usd = query("bet/"+uid[i]+"/sd");
			uqx = query("bet/"+uid[i]+"/qx");
			udd = query("bet/"+uid[i]+"/dd");
			usx = query("bet/"+uid[i]+"/sx");
			ukp = query("bet/"+uid[i]+"/kp");
			total = -(utc+udc+usd+uqx+udd+usx+ukp);
			if (utc)
				if (tc)
				{
					tell_object(me, name()+"赔给了你押中"+t["tc"]+"的"+MONEY_D->money_str(utc*b["tc"])+"。\n");
					me->add("balance", utc + utc*b["tc"]);
					total += utc + utc*b["tc"];
				} else tell_object(me, name()+"收走了你押在"+t["tc"]+"上的"+MONEY_D->money_str(utc)+"。\n");
			if (udc)
				if (dc)
				{
					tell_object(me, name()+"赔给了你押中"+t["dc"]+"的"+MONEY_D->money_str(udc*b["dc"])+"。\n");
					me->add("balance", udc + udc*b["dc"]);
					total += udc + udc*b["dc"];
				} else tell_object(me, name()+"收走了你押在"+t["dc"]+"上的"+MONEY_D->money_str(udc)+"。\n");
			if (usd)
				if (sd)
				{
					tell_object(me, name()+"赔给了你押中"+t["sd"]+"的"+MONEY_D->money_str(usd*b["sd"])+"。\n");
					me->add("balance", usd + usd*b["sd"]);
					total += usd + usd*b["sd"];
				} else tell_object(me, name()+"收走了你押在"+t["sd"]+"上的"+MONEY_D->money_str(usd)+"。\n");
			if (uqx)
				if (qx)
				{
					tell_object(me, name()+"赔给了你押中"+t["qx"]+"的"+MONEY_D->money_str(uqx*b["qx"])+"。\n");
					me->add("balance", uqx + uqx*b["qx"]);
					total += uqx + uqx*b["qx"];
				} else tell_object(me, name()+"收走了你押在"+t["qx"]+"上的"+MONEY_D->money_str(uqx)+"。\n");
			if (udd)
				if (dd)
				{
					tell_object(me, name()+"赔给了你押中"+t["dd"]+"的"+MONEY_D->money_str(udd*b["dd"])+"。\n");
					me->add("balance", udd + udd*b["dd"]);
					total += udd + udd*b["dd"];
				} else tell_object(me, name()+"收走了你押在"+t["dd"]+"上的"+MONEY_D->money_str(udd)+"。\n");
			if (usx)
				if (sx)
				{
					tell_object(me, name()+"赔给了你押中"+t["sx"]+"的"+MONEY_D->money_str(usx*b["sx"])+"。\n");
					me->add("balance", usx + usx*b["sx"]);
					total += usx + usx*b["sx"];
				} else tell_object(me, name()+"收走了你押在"+t["sx"]+"上的"+MONEY_D->money_str(usx)+"。\n");
			if (ukp)
				if (kp)
				{
					tell_object(me, name()+"赔给了你押中"+t["kp"]+"的"+MONEY_D->money_str(ukp*b["kp"])+"。\n");
					me->add("balance", ukp + ukp*b["kp"]);
					total += ukp + ukp*b["kp"];
				} else tell_object(me, name()+"收走了你押在"+t["kp"]+"上的"+MONEY_D->money_str(ukp)+"。\n");
			if (!total) message_vision(name()+ "唱道：$N本盘不赔不赚。\n", me);
			else if (total > 0) message_vision(name()+ "唱道：$N本盘净赚"+MONEY_D->money_str(total)+"。\n", me);
			else message_vision(name()+"唱道：$N本盘净赔"+MONEY_D->money_str(-total)+"。\n", me);
			if (!wiz_level(me)) tt += total/100;
		}
		cc++;
		if (debug) message("wiz:yuj", "赌场情况："+cc+" "+tt+"。\n", environment());
	}
	in_bet = 0;
	call_out("casino", 10);
}

