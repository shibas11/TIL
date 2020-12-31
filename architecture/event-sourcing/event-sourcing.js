class AggregateRoot {
    apply(event) {
        this.handle(event)
        return this
    }

    handle(event) {
        const eventName = event.constructor.name
        const eventMethod = `apply${eventName}`

        if (!this[eventMethod]) {
            throw new TypeError(`${eventMethod} is not a function`)
        }

        this[eventMethod](event)
    }
}

class BankAccount extends AggregateRoot {
    static open(id, name) {
        bankAccount = new BankAccount
        bankAccount.apply(new OpenedEvent(id, name))
        return bankAccount
    }
    applyOpenedEvent(event) {
        this.id = event.id
        this.name = event.name

        this.closed = false
        this.balance = 0
    }

    deposit(amount) {
        if (this.closed) {
            throw new Error(`${this.id} account is closed.`)
        }
        this.apply(new DepositedEvent(this.id, amount))
        return this
    }
    applyDepositedEvent(event) {
        this.balance += event.amount
    }

    withdraw(amount) {
        if (this.closed) {
            throw new Error(`${this.id} account is closed.`)
        }
        this.apply(new WithdrawnEvent(this.id, amount))
        return this
    }
    applyWithdrawnEvent(event) {
        this.balance -= event.amount
    }

    close() {
        if (!this.closed) {
            this.apply(new ClosedEvent(this.id))
        }
        return this
    }
    applyClosedEvent() {
        this.closed = true
    }
}

class OpenedEvent {
    constructor(id, name) {
        this.id = id
        this.name = name
    }
}
class DepositedEvent {
    constructor(id, amount) {
        this.id = id
        this.amount = amount
    }
}
class WithdrawnEvent {
    constructor(id, amount) {
        this.id = id
        this.amount = amount
    }
}
class ClosedEvent {
    constructor(id) {
        this.id = id
    }
}

var bankAccount = BankAccount.open(123, "Jake")
    .deposit(10000)
    .withdraw(1000)
    .deposit(3000)
    .close()
console.log(bankAccount)

const events = [
    new OpenedEvent(123, 'Jake'),
    new DepositedEvent(123, 10000),
    new WithdrawnEvent(123, 1000),
    new DepositedEvent(123, 3000),
    new ClosedEvent(123)
]
var jakeAccount = new BankAccount
events.forEach(event => jakeAccount.apply(event))
console.log(jakeAccount)
