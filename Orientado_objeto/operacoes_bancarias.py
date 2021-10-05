from conta_bank import cria_conta, deposita, saca, extrato

conta = cria_conta(123, "Nico", 55.0, 1000.0)
deposita(conta, 300.0)
extrato(conta)
saca(conta, 100.0)
extrato(conta)
 